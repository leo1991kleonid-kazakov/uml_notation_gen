#include "util.h"
#include "ast.h"
#include <map>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#ifndef WIN32
#include <sys/stat.h>
#else
#include <windows.h>
#endif

const char* visibility_str[] = {
		"private",
		"protected",
		"public"
};

Generator * Generator::create(Language lang, std::ostream& os)
{
	switch(lang) {
	case L_CPP:
		return new CppGenerator(os);
	case L_JAVA:
		return new JavaGenerator(os);
	case L_PASCAL:
		return new PascalGenerator(os);
	case L_OBJPASCAL:
		return new ObjPascalGenerator(os);
	default:
		throw "Invalid language";
	}
}

std::string JavaGenerator::genTypeName(N_Type* t) {
	std::stringstream ss;
	std::string name = t->getName();
	if (name.size() == 0)
		name = "void";
	ss << name;
	return ss.str();
}

std::string JavaGenerator::genField(N_Field* f)
{
	std::stringstream ss;
	ss << "\t" <<
			visibility_str[f->getVisibility()] << " " <<
			genTypeName(&f->getType()) << " " <<
			f->getName() << ";\n";
	return (ss.str());
}

std::string JavaGenerator::genMethod(N_Class* c, N_Method* m)
{
	std::stringstream ss;
	ss << "\t" << visibility_str[m->getVisibility()] << " ";
	if (m->isStatic())
		ss << "static ";
	ss << genTypeName(&m->getType()) << " " << m->getName() << "(";
	for (int i=0; i < m->getParamCount(); i++) {
		if (i > 0)
			ss << ", ";
		ss << genParameter(&(*m)[i]);
	}
	ss<<")";
	std::vector<N_Exception> ex = m->getExceptions();
	if(ex.size() >0) {
		ss<<" throws ";
		for (int i = 0; i < ex.size(); i++) {
			if(i != 0)
				ss << ", ";
			ss << ex[i].getName();
		}
	}
	ss << " {\n\t}\n\n";
	return (ss.str());
}

std::string JavaGenerator::genParameter(N_Param* p) {
	std::stringstream ss;
	ss << genTypeName(&p->getType());
	ss << " " << p->getName();
	return(ss.str());
}

std::string JavaGenerator::genClass(N_Class* c) {
	std::stringstream ss;

	ss << "public class " << c->getName();
	if (int sz = c->getAncestorClasses().size() > 0) {
		ss << " extends ";
		for (int i = 0; i < sz; i++) {
			if (i != 0) {
				std::cerr << "Java doesn't support multiple inheritance.";
				break;
			} else
				ss << c->getAncestorClasses()[i].getName();
		}
	}
	if (int sz = c->getAncestorInterfaces().size() > 0) {
		ss << " implements ";
		for (int i = 0; i < sz; i++) {
			if (i != 0)
				ss << ", ";
			ss << c->getAncestorInterfaces()[i].getName();
		}
	}
	ss << " {\n";

	auto fields = c->getFields();
	for (int i = 0; i < fields.size(); i++) {
		N_Field *fld = static_cast<N_Field*>(&fields[i]);
		ss << genField(fld);
	}

	ss << "\n";

	auto methods = c->getMethods();
	for (int i = 0; i < methods.size(); i++) {
		N_Method *met = static_cast<N_Method*>(methods[i]);
		ss << genMethod(nullptr, met);
	}

	ss << "}\n\n";
	return(ss.str());
}

std::string JavaGenerator::genInterface(N_Interface* c) {
	std::stringstream ss;

	ss << "public interface " << c->getName();
	if (int sz = c->getAncestorInterfaces().size() > 0) {
		ss << " extends ";
		for (int i = 0; i < sz; i++) {
			if (i != 0)
				ss << ", ";
			ss << c->getAncestorInterfaces()[i].getName();
		}
	}
	ss << " {\n";

	auto methods = c->getMethods();
	for (int i = 0; i < methods.size(); i++) {
		N_Method *met = static_cast<N_Method*>(methods[i]);
		ss << genMethodHeader(met, false);
	}

	ss << "}\n\n";
	return(ss.str());
}

std::string JavaGenerator::genMethodHeader(N_Method* m, bool pure) {
	std::stringstream ss;
	ss << "\t" << visibility_str[m->getVisibility()] << " ";
	if (pure)
		ss << "abstract ";
	ss << genTypeName(&m->getType()) << " " << m->getName() << "(";
	for (int i=0; i < m->getParamCount(); i++) {
		if (i > 0)
			ss << ", ";
		ss << genParameter(&(*m)[i]);
	}
	ss<<")";
	std::vector<N_Exception> ex = m->getExceptions();
	if(ex.size() >0) {
		ss<<" throws ";
		for (int i = 0; i < ex.size(); i++) {
			if(i != 0)
				ss << ", ";
			ss << ex[i].getName();
		}
	}
	ss << ";\n";
	return (ss.str());
}

std::string CppGenerator::genTypeName(N_Type* t) {
	std::stringstream ss;
	std::string name = t->getName();
	if (name.size() == 0)
		name = "void";
	name = replaceStr(name, "[]", "*");
	ss << name;
	return ss.str();
}

std::string CppGenerator::genField(N_Field* f) {
	std::stringstream ss;

	ss << "\t" << genTypeName(&f->getType()) << " " << f->getName() << ";\n";
	return (ss.str());
}

std::string CppGenerator::genClass(N_Class* c) {
	std::map <MemberVisibility, std::vector<N_ClassMember*>> ff;
	std::stringstream ss;
	std::vector<std::string> ancestors;

	ss << "class " << c->getName();

	if (int sz = c->getAncestorClasses().size() > 0) {
		for (int i = 0; i < sz; i++) {
			ancestors.push_back(c->getAncestorClasses()[i].getName());
		}
	}

	if (int sz = c->getAncestorInterfaces().size() > 0) {
		for (int i = 0; i < sz; i++) {
			ancestors.push_back(c->getAncestorInterfaces()[i].getName());
		}
	}

	if (int sz = ancestors.size() > 0) {
		ss << ": ";
		for (int i = 0; i < sz; i++) {
			if (i != 0)
				ss << ", ";
			ss << "public " << ancestors[i];
		}
	}
	ss << "\n{\n";

	auto fields = c->getFields();
	for (int i = 0; i < fields.size(); i++) {
		ff[fields[i].getVisibility()].push_back(&fields[i]);
	}

	auto methods = c->getMethods();
	for (int i = 0; i < methods.size(); i++) {
		ff[methods[i]->getVisibility()].push_back(methods[i]);
	}

	for(auto i = ff.begin(); i != ff.end(); i++) {
		ss << visibility_str[i->first] << ":\n";
		for (int k = 0; k < i->second.size(); k++) {
			N_ClassMember *mb = i->second[k];
			N_Field *fld = dynamic_cast<N_Field*>(mb);
			N_Method *met = dynamic_cast<N_Method*>(mb);
			if (fld)
				ss << genField(fld);
			if (met)
				ss << genMethodHeader(met);
		}
	}

	ss << "};\n\n";

	return ss.str();
}

std::string CppGenerator::genMethodHeader(N_Method* m, bool pure) {
	std::stringstream ss;
	ss << "\t";
	N_Constructor *ctor = dynamic_cast<N_Constructor*>(m);
	N_Destructor *dtor = dynamic_cast<N_Destructor*>(m);
	if (ctor) {

	} else if (dtor) {
		ss << "virtual ~";
	} else {
		if (m->isStatic())
			ss << "static ";
		else
			ss << "virtual ";
		ss << genTypeName(&m->getType()) << " ";
	}
	ss << m->getName() << "(";
	for (int i=0; i < m->getParamCount(); i++) {
		if (i > 0)
			ss << ", ";
		ss << genParameter(&(*m)[i]);
	}
	ss<<")";
	std::vector<N_Exception> ex = m->getExceptions();
	if(ex.size() >0) {
		ss<<" throw(";
		for (int i = 0; i < ex.size(); i++) {
			if(i != 0)
				ss << ", ";
			ss << ex[i].getName();
		}
		ss << ")";
	}
	if (pure)
		ss << " = 0;\n";
	else
		ss << ";\n";
	return (ss.str());
}

std::string CppGenerator::genMethod(N_Class* c, N_Method* m) {
	std::stringstream ss;
	N_Constructor *ctor = dynamic_cast<N_Constructor*>(m);
	N_Destructor *dtor = dynamic_cast<N_Destructor*>(m);
	if (ctor) {
	} else if (dtor) {
	} else {
		ss << genTypeName(&m->getType()) << " ";
	}

	ss << c->getName() << "::";
	if (dtor)
		ss << "~";
	ss << m->getName() << "(";
	for (int i=0; i < m->getParamCount(); i++) {
		if (i > 0)
			ss << ", ";
		ss << genParameter(&(*m)[i]);
	}
	ss<<")";
	std::vector<N_Exception> ex = m->getExceptions();
	if(ex.size() >0) {
		ss<<" throw(";
		for (int i = 0; i < ex.size(); i++) {
			if(i != 0)
				ss << ", ";
			ss << ex[i].getName();
		}
		ss << ")";
	}
	ss << "\n{\n}\n\n";
	return (ss.str());
}

std::string CppGenerator::genParameter(N_Param* p) {
	std::stringstream ss;
	ss << genTypeName(&p->getType());
	if (p->getDirection() != FD_IN)
		ss << "&";
	ss << " " << p->getName();
	return(ss.str());
}
std::string CppGenerator::genInterface(N_Interface* c) {
	std::map <MemberVisibility, std::vector<N_Method*>> ff;
	std::stringstream ss;

	ss << "class " << c->getName();
	if (int sz = c->getAncestorInterfaces().size() > 0) {
		ss << ": ";
		for (int i = 0; i < sz; i++) {
			if (i != 0)
				ss << ", ";
			ss << "public " << c->getAncestorInterfaces()[i].getName();
		}
	}
	ss << "\n{\n";

	auto methods = c->getMethods();
	for (int i = 0; i < methods.size(); i++) {
		ff[methods[i]->getVisibility()].push_back(methods[i]);
	}
	for(auto i = ff.begin(); i != ff.end(); i++) {
		ss << visibility_str[i->first] << ":\n";
		for (int k = 0; k < i->second.size(); k++) {
			N_Method *met = static_cast<N_Method*>(i->second[k]);
			ss << genMethodHeader(met, true);
		}
	}

	ss << "};\n\n";

	return ss.str();
}

std::string PascalGenerator::genTypeName(N_Type* t) {
	std::stringstream ss;
	return ss.str();
}

std::string PascalGenerator::genField(N_Field* f) {
	std::stringstream ss;
//	ss<<f.getName()<<": "<<f.getType().getName()<<";\n";
	return (ss.str());
}

std::string PascalGenerator::genMethodHeader(N_Method* m, bool pure)
{
	std::stringstream ss;
//	N_Constructor *c=dynamic_cast<N_Constructor*> (&m);
//	N_Destructor *d=dynamic_cast<N_Destructor*> (&m);
//	if(c !=nullptr) {
//		ss<<"constructor "<<m.getName();
//	}
//	else if(d !=nullptr)
//		ss<<"destructor "<<m.getName();
//	else if(m.getType().getName().size() ==0)
//		ss<<"procedure "<<m.getName();
//	else
//		ss<<"function "<<m.getName();
//	if (m.getParamCount() !=0) {
//		ss<<"(";
//		for (int i =0; i< m.getParamCount(); i++) {
//			if(m[i].getDirection() != FD_IN)
//				ss<<"var ";
//			ss<<m[i].getName()<<":"<<m[i].getType().getName();
//			if(i <m.getParamCount()-1)
//				ss<<";";
//		}
//		ss<<")";
//	}
//	ss<<";";
//	if(c ==nullptr)
//		ss<<"virtual;";
//	ss<<"\n";
	return ss.str();
}

std::string PascalGenerator::genMethod(N_Class* c, N_Method* m) {
	std::stringstream ss;
//	N_Constructor *c=dynamic_cast<N_Constructor*> (&m);
//	N_Destructor *d=dynamic_cast<N_Destructor*> (&m);
//	if(c !=nullptr) {
//		ss<<"constructor "<<m.getName();
//	}
//	else if(d !=nullptr)
//		ss<<"destructor "<<m.getName();
//	else if(m.getType().getName().size() ==0)
//		ss<<"procedure "<<m.getName();
//	else
//		ss<<"function "<<m.getName();
//	if (m.getParamCount() !=0) {
//		ss<<"(";
//		for (int i =0; i< m.getParamCount(); i++) {
//			if(m[i].getDirection() != FD_IN)
//				ss<<"var ";
//			ss<<m[i].getName()<<":"<<m[i].getType().getName();
//			if(i <m.getParamCount()-1)
//				ss<<";";
//		}
//		ss<<")";
//	}
//	ss<<";";
//	if(c ==nullptr)
//		ss<<"virtual;";
//	ss<<"\n";
	return ss.str();
}

std::string PascalGenerator::genParameter(N_Param* p)
{
	std::stringstream ss;
	// TODO
	return ss.str();
}

std::string PascalGenerator::genInterface(N_Interface* c) {
	std::stringstream ss;
	ss<<"{error - interfaces are not supported. }\n";
	return ss.str();
}
std::string PascalGenerator::genClass(N_Class* c) {
	std::stringstream ss;
//	ss<<"type "<<c.getName()<<"=object";
//	if(c.getAncestorClasses().size() >0)
//		ss<<"("<<c.getAncestorClasses()[0].getName()<<")";
//	ss<<"\n";
//	std::map <MemberVisibility, std::vector<N_ClassMember>> ff;
//	for (int i = 0; i < c.getFields().size(); i++)
//		ff[c.getFields()[i].getVisibility()].push_back(c.getFields()[i]);
//	for (int i = 0; i < c.getMethods().size(); i++)
//		ff[c.getMethods()[i].getVisibility()].push_back(c.getMethods()[i]);
//	for(auto i =ff.begin(); i!=ff.end(); i++) {
//		ss<<visibility_str[i->first]<<"\n";
//		for (int k = 0; k < i->second.size(); k++) {
//			N_Field *fi = dynamic_cast<N_Field*>(&i->second[k]);
//			if (fi != nullptr)
//				ss << genField(*fi);
//			N_Method *met = dynamic_cast<N_Method*>(&i->second[k]);
//			if (met != nullptr)
//				ss << genMethodHeader(*met);
//		}
//	}
	return(ss.str());
}

std::string ObjPascalGenerator::genTypeName(N_Type* t) {
	std::stringstream ss;
	return ss.str();
}

std::string ObjPascalGenerator::genField(N_Field* f) {
	std::stringstream ss;
//	ss<<f.getName()<<": "<<f.getType().getName()<<";\n";
	return (ss.str());
}

std::string ObjPascalGenerator::genMethodHeader(N_Method* m, bool pure) {
	std::stringstream ss;
//	N_Constructor *c=dynamic_cast<N_Constructor*> (&m);
//	N_Destructor *d=dynamic_cast<N_Destructor*> (&m);
//	if(c !=nullptr) {
//		ss<<"constructor "<<m.getName();
//	}
//	else if(d !=nullptr)
//		ss<<"destructor "<<m.getName();
//	else if(m.getType().getName().size() ==0)
//		ss<<"procedure "<<m.getName();
//	else
//		ss<<"function "<<m.getName();
//	if (m.getParamCount() !=0) {
//		ss<<"(";
//		for (int i =0; i< m.getParamCount(); i++) {
//			if(m[i].getDirection() != FD_IN)
//				ss<<"var ";
//			ss<<m[i].getName()<<":"<<m[i].getType().getName();
//			if(i <m.getParamCount()-1)
//				ss<<";";
//		}
//		ss<<")";
//	}
//	ss<<";";
//	if(c ==nullptr)
//		ss<<"virtual;";
//	ss<<"\n";
	return ss.str();
}

std::string ObjPascalGenerator::genMethod(N_Class* c, N_Method* m) {
	std::stringstream ss;
//	N_Constructor *c=dynamic_cast<N_Constructor*> (&m);
//	N_Destructor *d=dynamic_cast<N_Destructor*> (&m);
//	if(c !=nullptr) {
//		ss<<"constructor "<<m.getName();
//	}
//	else if(d !=nullptr)
//		ss<<"destructor "<<m.getName();
//	else if(m.getType().getName().size() ==0)
//		ss<<"procedure "<<m.getName();
//	else
//		ss<<"function "<<m.getName();
//	if (m.getParamCount() !=0) {
//		ss<<"(";
//		for (int i =0; i< m.getParamCount(); i++) {
//			if(m[i].getDirection() != FD_IN)
//				ss<<"var ";
//			ss<<m[i].getName()<<":"<<m[i].getType().getName();
//			if(i <m.getParamCount()-1)
//				ss<<";";
//		}
//		ss<<")";
//	}
//	ss<<";";
//	if(c ==nullptr)
//		ss<<"virtual;";
//	ss<<"\n";
	return ss.str();
}

std::string ObjPascalGenerator::genParameter(N_Param* p)
{
	std::stringstream ss;
	// TODO
	return ss.str();
}

std::string ObjPascalGenerator::genInterface(N_Interface* c) {
	std::stringstream ss;
//	ss<<"type "<<c.getName()<<"=interface";
//	if (c.getAncestorInterfaces().size() > 0)
//		for (int k = 1; k < c.getAncestorInterfaces().size(); k++)
//			ss << "(" << c.getAncestorInterfaces()[k].getName()<<",";
//	ss<<")\n";
//
//	std::map <MemberVisibility, std::vector<N_ClassMember>> ff;
//
//	for (int i = 0; i < c.getMethods().size(); i++)
//		ff[c.getMethods()[i].getVisibility()].push_back(c.getMethods()[i]);
//	for(auto i =ff.begin(); i!=ff.end(); i++) {
//		ss << visibility_str[i->first] << "\n";
//		for (int k = 0; k < i->second.size(); k++) {
//			N_Field *fi = dynamic_cast<N_Field*>(&i->second[k]);
//			if(fi != nullptr)
//				ss << genField(*fi);
//			N_Method *met = dynamic_cast<N_Method*>(&i->second[k]);
//			if(met !=nullptr)
//				ss << genMethodHeader(*met);
//		}
//	}
	return(ss.str());
}


std::string ObjPascalGenerator::genClass(N_Class* c) {
	std::stringstream ss;
//	ss<<"type "<<c.getName()<<"=class";
//	if(c.getAncestorClasses().size() >0)
//		ss<<"("<<c.getAncestorClasses()[0].getName()<<")";
//	ss<<"\n";
//	std::map <MemberVisibility, std::vector<N_ClassMember>> ff;
//	for (int i = 0; i < c.getFields().size(); i++)
//		ff[c.getFields()[i].getVisibility()].push_back(c.getFields()[i]);
//	for (int i = 0; i < c.getMethods().size(); i++)
//		ff[c.getMethods()[i].getVisibility()].push_back(c.getMethods()[i]);
//	for(auto i =ff.begin(); i!=ff.end(); i++) {
//		ss<<visibility_str[i->first]<<"\n";
//		for (int k = 0; k < i->second.size(); k++) {
//			N_Field *fi = dynamic_cast<N_Field*>(&i->second[k]);
//			if (fi != nullptr)
//				ss << genField(*fi);
//			N_Method* met = dynamic_cast<N_Method*>(&i->second[k]);
//			if (met != nullptr)
//				ss << genMethodHeader(*met);
//		}
//	}
	return(ss.str());
}

void CppGenerator::generate(N_Model& m)
{
	std::ofstream header;
	std::ofstream source;

	std::string model_name = m.getName();
	std::string model_header_name = model_name + ".h";
	std::string model_source_name = model_name + ".cc";

	header.open(model_header_name.c_str());
	source.open(model_source_name.c_str());

	std::string model_macro_name = model_header_name;
	std::replace(model_macro_name.begin(), model_macro_name.end(), '.', '_');
	std::transform(model_macro_name.begin(), model_macro_name.end(), model_macro_name.begin(), ::toupper);

	header << "#ifndef " << model_macro_name << "\n";
	header << "#define " << model_macro_name << "\n\n";

	source << "#include \"" << model_header_name << "\"\n\n";

	int member_count = m.getMemberCount();
	for (int i = 0; i < member_count; i++) {
		N_ModelMember *member = m.getMember(i);
		LOG << "Generating member '" << member->getName() << "'\n";
		switch(member->getType()) {
		case MMT_TYPE:
			{
				N_Type *t = static_cast<N_Type*>(member);
				if (t->isBuiltin())
					break;
				header << "typedef " << genTypeName(new N_Type(t->getAliasedType())) << " " << t->getName() << ";\n\n";
			}
			break;
		case MMT_INTERFACE:
			{
				N_Interface *ifc = static_cast<N_Interface*>(member);
				header << genInterface(ifc);
			}
			break;
		case MMT_CLASS:
			{
				N_Class *cls = static_cast<N_Class*>(member);
				header << genClass(cls);
				for (auto m: cls->getMethods()) {
					source << genMethod(cls, m);
				}
			}
			break;
		default:
			LOG << "Wat\n";
		}

	}


	header << "\n#endif /* " << model_macro_name << " */\n";
}

void JavaGenerator::generate(N_Model& m)
{
	std::ofstream source;

	std::string model_name = m.getName();

#ifndef WIN32
	const int dir_err = mkdir(model_name.c_str(), S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (-1 == dir_err) {
		std::cerr << "Unable to create directory " << model_name << "\n";
// FIXME
//		return;
	}
#else
	CreateDirectory(model_name.c_str(), NULL);
#endif


#ifndef WIN32
	std::string model_dir = model_name + "/";
#else
	std::string model_dir = model_name + "\\";
#endif

	int member_count = m.getMemberCount();
	for (int i = 0; i < member_count; i++) {
		N_ModelMember *member = m.getMember(i);
		LOG << "Generating member '" << member->getName() << "'\n";
		switch(member->getType()) {
		case MMT_TYPE:
			{
				LOG << "Custom types are not supported in Java.\n";
			}
			break;
		case MMT_INTERFACE:
			{
				N_Interface *ifc = static_cast<N_Interface*>(member);
				std::string model_source_name = model_dir + "/" + ifc->getName() + ".java";
				source.open(model_source_name.c_str());
				source << "package " << model_name << ";\n\n";
				source << genInterface(ifc);
				source.close();
			}
			break;
		case MMT_CLASS:
			{
				N_Class *cls = static_cast<N_Class*>(member);
				std::string model_source_name = model_dir + "/" + cls->getName() + ".java";
				source.open(model_source_name.c_str());
				source << "package " << model_name << ";\n\n";
				source << genClass(cls);
				source.close();
			}
			break;
		default:
			LOG << "Wat\n";
		}

	}

}

void PascalGenerator::generate(N_Model& m)
{

}

void ObjPascalGenerator::generate(N_Model& m)
{

}

