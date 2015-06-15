/** @file ast.h
 * Содержит объявления классов элементов дерева синтаксического разбора и генераторов для них
 */

#ifndef AST_H_
#define AST_H_

#include <string>
#include <vector>
#include <iostream>

/** @enum Language
 * Языки, для которых может быть сгенерирован шаблон
 */
enum Language
{
	L_CPP, ///< C++
	L_JAVA, ///< Java
	L_PASCAL, ///< Borland Pascal и FreePascal
	L_OBJPASCAL ///< ObjectPascal и Objective FreePascal
};

enum ModelMemberType {
	MMT_UNDEFINED,
	MMT_OPTION,
	MMT_TYPE,
	MMT_CLASS,
	MMT_INTERFACE
};

/** @class ModelMember
 *  Произвольный элемент модели
 */
class N_ModelMember
{
protected:
	std::string m_name; ///< Содержит имя элемента модели
	ModelMemberType m_type; ///< Содержит тип элемента модели (обход бага в RTTI у некоторых компиляторов)
public:
	/** Конструктор
	 * @param name - имя элемента модели
	 */
	explicit N_ModelMember(const std::string& name): m_name(name), m_type(MMT_UNDEFINED) {}
	/** Деструктор */
	virtual ~N_ModelMember () {}
	/** Получение имени элемента модели
	 * @return имя элемента модели
	 */
	virtual std::string getName() const { return m_name; }
	virtual ModelMemberType getType() const { return m_type; }
};

class N_ModelOption: public N_ModelMember
{
protected:
	std::string m_value; ///< Содержит значение опции
public:
	/** Конструктор
	 * @param name - имя опции
	 * @param value - значение опции
	 */
	N_ModelOption(const std::string& name, const std::string& value): N_ModelMember(name), m_value(value) { m_type = MMT_OPTION; }
	/** Деструктор */
	virtual ~N_ModelOption() {}
	/** Получение значение опции
	 * @return значение опции
	 */
	virtual std::string getValue() const { return m_value; }
};

/** @class Model
 * Классовая модель, корневой узел
 */
class N_Model
{
protected:
	std::string m_name; ///< Имя модели
	std::vector <N_ModelMember*> m_members; ///< Коллекция элементов модели
	std::vector <N_ModelOption> m_options; ///< Коллекция опций модели
public:
	/** Конструктор
	 * @param name - имя модели
	 */
	explicit N_Model(const std::string& name): m_name(name) {}
	/** Деструктор */
	virtual ~N_Model() {}
	/** Получение имени модели
	 * @return имя модели
	 */
	virtual std::string getName() const { return (m_name); }
	/** Добавление элемента модели
	 * @param member - добавляемый элемент
	 */
	virtual void addMember(N_ModelMember *member)
	{
		m_members.push_back(member);
	}
	virtual int getMemberCount() const { return m_members.size(); }
	virtual N_ModelMember* getMember(int index) { return m_members[index]; }
	/** Добавление опции модели
	 * @param option - добавляемая опция
	 */
	virtual void addOption(N_ModelOption& option)
	{
		m_options.push_back(option);
	}
	virtual int getOptionCount() const { return m_options.size(); }
	virtual N_ModelOption& getOption(int index) { return m_options[index]; }
};

/** @class N_Type
 * Нетерминал, обозначающий тип данных
 */
class N_Type: public N_ModelMember
{
protected:
	bool m_builtin; ///< Является ли тип встроенным
	std::string m_aliased_type; ///< Исходный тип
public:
	/** Конструктор встроенного типа
	 * @param name - имя типа данных
	 */
	explicit N_Type(const std::string& name): N_ModelMember(name), m_builtin(true) { m_type = MMT_TYPE; }
	/** Конструктор типа-псевдонима
	 * @param name - имя типа данных
	 * @param original - имя исходного типа
	 */
	N_Type(const std::string& name, const std::string& original): N_ModelMember(name), m_aliased_type(original), m_builtin(false) {  m_type = MMT_TYPE; }
	/** Копирующий конструктор
	 * @param t - оригинальный экземпляр
	 */
	N_Type(const N_Type& t): N_ModelMember(t.m_name), m_builtin(t.m_builtin), m_aliased_type(t.m_aliased_type) {}
	/** Деструктор */
	virtual ~N_Type() {}
	/** Получение имени исходного типа
	 * @return имя исходного типа
	 */
	virtual std::string getAliasedType() const { return m_aliased_type; }
	/** Является ли тип встроенным
	 * @return true, если тип встроенный, иначе false
	 */
	virtual bool isBuiltin() const { return m_builtin; }
};

/** @enum MemberVisibility
 * Области видимости членов класса
 */
enum MemberVisibility
{
	MV_PRIVATE, ///< Область private
	MV_PROTECTED, ///< Область protected
	MV_PUBLIC ///< Область public
};

/** @class N_ClassMember
 * Член класса
 */
class N_ClassMember: public N_ModelMember
{
protected:
	N_Type m_type; ///< Тип члена класса
	MemberVisibility m_vis; ///< Область видимости члена класса
	bool m_static; ///< Является ли член класса статическим
public:
	/** Конструктор
	 * @param name - имя члена класса
	 * @param type - тип члена класса
	 * @param vis - область видимости члена класса
	 */
	N_ClassMember(
			const std::string& name,
			const std::string& type,
			MemberVisibility vis = MV_PRIVATE): N_ModelMember(name), m_type(type), m_vis(vis), m_static(false) {}
	/** Деструктор */
	virtual ~N_ClassMember() {}
	/** Получение типа члена класса
	 * @return тип члена класса
	 */
	virtual N_Type& getType() { return (m_type); }
	/** Получение области видимости члена класса
	 * @return область видимости члена класса
	 */
	virtual MemberVisibility getVisibility() const { return (m_vis); }

	/** Установка признака статического члена класса
	 * @param st - значение признака
	 */
	virtual void setStatic(bool st) { m_static = st; }
	/** Получение признака статического члена класса
	 * @return значение признака
	 */
	virtual bool isStatic() const { return m_static; }
};

/** @class N_Field
 * Нетерминал, обозначающий поле класса
 */
class N_Field: public N_ClassMember
{
public:
	/** Конструктор
	 * @param name - имя поля
	 * @param type - тип поля
	 * @param vis - область видимости поля
	 */
	N_Field(
			const std::string& name,
			const std::string& type,
			MemberVisibility vis = MV_PRIVATE): N_ClassMember(name, type, vis) {}
	/** Деструктор */
	virtual ~N_Field() {}
};

/** @enum ParamDirection
 * Направление параметра
 */
enum ParamDirection
{
	FD_IN, ///< Входной параметр, допускается передача константы
	FD_OUT, ///< Выходной параметр, передается ссылка или указатель, инициализация не требуется
	FD_INOUT ///< Входной и выходной параметр, передается ссылка или указатель, требуется инициализация
};

/** @class N_Param
 * Параметр метода
 */
class N_Param: public N_Field
{
private:
	/** Получение области видимости параметра. Поскольку таковой не существует, метод предка скрыт. */
	virtual MemberVisibility getVisibility() = delete; // const { return (N_ClassMember::getVisibility()); }
protected:
	ParamDirection m_dir; ///< Направление параметра
public:
	/** Конструктор
	 * @param name - имя параметра
	 * @param type - тип параметра
	 * @param dir - направление параметра
	 */
	N_Param(
			const std::string& name,
			const std::string& type,
			ParamDirection dir = FD_IN): N_Field(name, type), m_dir(dir) {}
	/** Деструктор */
	virtual ~N_Param() {}
	/** Получение направления параметра
	 * @return Направление параметра
	 */
	virtual ParamDirection getDirection () {
		return (m_dir);
	}
};

class N_Method;

/** @class N_Interface
 * Нетерминал, обозначающий интерфейс
 */
class N_Interface: public N_ModelMember
{
protected:
	std::vector<N_Method*> m_methods; ///< Коллекция методов интерфейса
	std::vector<N_Interface> m_ancestor_interfaces; ///< Коллекция интерфейсов-предков
public:
	/** Конструктор
	 * @param name - имя интерфейса
	 */
	N_Interface (std::string name): N_ModelMember(name) { m_type = MMT_INTERFACE; }
	/** Деструктор */
	virtual ~N_Interface() {}
	/** Добавление метода
	 * @param method - метод, который необходимо добавить в интерфейс
	 */
	virtual void addMethod(N_Method* method) { m_methods.push_back(method); }
	/** Получение коллекции методов интерфейса
	 * @return Коллекция методов интерфейса
	 */
	virtual std::vector<N_Method*> getMethods() { return (m_methods); }
	/** Добавление интерфейса-предка
	 * @param i - интерфейс, который необходимо добавить в качестве предка
	 */
	virtual void addAncestorInterface(N_Interface& i) { m_ancestor_interfaces.push_back(i); }
	/** Получение коллекции интерфейсов-предков
	 * @return Коллекция интерфейсов-предков
	 */
	virtual std::vector<N_Interface> getAncestorInterfaces() { return(m_ancestor_interfaces); }
};

/** @class N_Class
 * Нетерминал, обозначающий класс.
 */
class N_Class: public N_Interface
{
protected:
	std::vector<N_Field> m_fields; ///< Коллекция полей класса
	std::vector<N_Class> m_ancestor_classes; ///< Коллекция классов-предков
public:
	/** Конструктор
	 * @param name - имя класса
	 */
	N_Class(std::string name): N_Interface(name) { m_type = MMT_CLASS; }
	/** Деструктор */
	virtual ~N_Class() {}
	/** Добавление поля в класс
	 * @param field - поле, которе необходимо добавить в класс
	 */
	virtual void addField(N_Field field) { m_fields.push_back(field); }
	/** Получение коллекции полей класса
	 * @return Коллекция полей класса
	 */
	virtual std::vector<N_Field> getFields() { return (m_fields); }
	/** Добавление класса-предка
	 * @param c - класс, который необходимо добавить в качестве предка
	 */
	virtual void addAncestorClass(N_Class& c) { m_ancestor_classes.push_back(c); }
	/** Получение коллекции классов-предков
	 * @return Коллекция классов-предков
	 */
	virtual std::vector<N_Class> getAncestorClasses() { return(m_ancestor_classes); }
};

/** @class N_Exception
 * Нетерминал, обозначающий класс-исключение
 */
class N_Exception: public N_Class
{
public:
	/** Конструктор
	 * @param name - имя исключения
	 */
	N_Exception(std::string name): N_Class(name) {}
	/** Деструктор */
	virtual ~N_Exception() {}
};


/** @enum MethodType
 * Типы методов
 */
enum MethodType {
	MT_FUNCTION, ///< Метод объекта, возвращающий значение
	MT_PROCEDURE, ///< Метод объекта, не возвращающий значение
	MT_CONSTRUCTOR, ///< Конструктор объекта
	MT_DESTRUCTOR, ///< Деструктор объекта
	MT_STATIC_PROCEDURE, ///< Метод класса, возвращающий значение
	MT_STATIC_FUNCTION ///< Метод класса, не возвращающий значение
};

/** @struct MethodTypeInfo
 * Информация о типе метода
 */
struct MethodTypeInfo {
	std::string *return_type; ///< Тип возвращаемого значения
	MethodType method_type; ///< Тип метода
};

/** @class N_Method
 * Нетерминал, обозначающий метод класса или интерфейса
 */
class N_Method: public N_ClassMember
{
protected:
	std::vector<N_Param> m_params; ///< Коллекция параметров метода
	std::vector<N_Exception> exceptions; ///< Коллекция исключений, выкидываемых методом
public:
	/** Конструктор
	 * @param name - имя метода
	 * @param type - тип значения, возвращаемого методом
	 * @param vis - область видимости метода
	 */
	N_Method(
			const std::string& name,
			const std::string& type,
			MemberVisibility vis = MV_PRIVATE): N_ClassMember(name, type, vis) {}
	/** Деструктор */
	virtual ~N_Method() {}
	/** Добавление параметра метода
	 * @param - параметр, который необходимо добавить в метод
	 */
	virtual void addParam(N_Param& param) { m_params.push_back(param); }
	/** Получение количества параметров метода
	 * @return Количество параметров метода
	 */
	virtual int getParamCount() { return (m_params.size()); }
	/** Добавление исключения
	 * @param ex - исключение, которое необходимо добавить
	 */
	virtual void addException(N_Exception ex) { exceptions.push_back(ex); }
	/** Получение коллекции исключений, выкидываемых методом
	 * @return Коллекция исключений, выкидываемых методом
	 */
	virtual std::vector<N_Exception> getExceptions() { return(exceptions); }
	/** Получение параметра метода по его номеру
	 * @param n - номер параметра, считая от 0
	 * @return Выбранный параметр метода
	 */
	virtual N_Param& operator[](int n) { return m_params[n]; }
};

/** @class N_Constructor
 * Нетерминал, обозначающий конструктор
 */
class N_Constructor: public N_Method {
public:
	/** Конструктор
	 * @param name - имя конструктора (если применимо)
	 * @param vis - область видимости конструктора
	 */
	N_Constructor(
			const std::string& name,
			MemberVisibility vis = MV_PRIVATE): N_Method(name, std::string(), vis) {}
	/** Деструктор */
	virtual ~N_Constructor() {}
};

/** @class N_Destructor
 * Нетерминал, обозначающий деструктор
 */
class N_Destructor: public N_Method {
public:
	/** Конструктор
	 * @param name - имя деструктора (если применимо)
	 * @param vis - область видимость деструктора
	 */
	N_Destructor(
			const std::string& name,
			MemberVisibility vis = MV_PRIVATE): N_Method(name, std::string(), vis) {}
	/** Деструктор */
	virtual ~N_Destructor() {}
};

/** @enum Stereotype
 * Стереотипы методов
 */
enum Stereotype {
	ST_NONE, ///< Нет стереотипа
	ST_STATIC, ///< Классовый метод
	ST_CONSTRUCTOR, ///< Конструктор
	ST_DESTRUCTOR ///< Деструктор
};

/** @class Generator
 * Абстрактный класс генератора шаблона кода
 */
class Generator
{
protected:
	std::ostream& m_os; ///< Поток вывода шаблона
	/** Конструктор
	 * @param os - поток, в который необходимо выдавать шаблон
	 */
	explicit Generator(std::ostream& os): m_os(os) { }
public:
	/** Генератор шаблона модели
	 * @param m - модель, для которой необходимо сгенерировать шаблон
	 */
	virtual void generate(N_Model& m) = 0;
	/** Генератор шаблона имени типа
	 * @param t - тип, имя которого необходимо привести в соответствие с языком
	 * @return Сгенерированное имя типа
	 */
	virtual std::string genTypeName(N_Type* t) = 0;
	/** Генератор шаблона интерфейса
	 * @param c - интерфейс, для которого необходимо сгенерировать шаблон
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genInterface(N_Interface* c) = 0;
	/** Генератор шаблона поля класса
	 * @param f - поле, для которого необходимо сгенерировать шаблон
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genField(N_Field* f) = 0;
	/** Генератор шаблона метода
	 * @param c - класс, для метода которого необходимо сгенерировать шаблон
	 * @param m - метод, для которого необходимо сгенерировать шаблон
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genMethod(N_Class* c, N_Method* m) = 0;
	/** Генератор шаблона заголовка метода
	 * @param m - метод, для которого необходимо сгенерировать шаблон
	 * @param pure - признак абстрактного метода
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genMethodHeader(N_Method* m, bool pure = false) = 0;
	/** Генератор шаблона параметра метода
	 * @param p - параметр, для которого необходимо сгенерировать шаблон
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genParameter(N_Param* p) = 0;
	/** Генератор шаблона класса
	 * @param c - класс, для которого необходимо сгенерировать шаблон
	 * @return Сгенерированный шаблон
	 */
	virtual std::string genClass(N_Class* c) = 0;
	/** Деструктор */
	virtual ~Generator() {}
	/** Классовый метод для создания экземпляра генератора
	 * @param lang - язык, для которого требуется создать генератор
	 * @param os - поток вывода, в который предполагается выводить шаблон
	 * @return Экземпляр генератора
	 */
	static Generator *create(Language lang, std::ostream& os);

	/** Оператор вывода компонента модели в поток вывода шаблона
	 * @param os - поток вывода, в который выводится шаблон компонента модели
	 * @param mm - выводимый компонент модели
	 * @return Поток вывода, в который был выведен шаблон
	 */
	friend std::ostream& operator<<(Generator& os, const N_ModelMember& mm);
};

/** @class CppGenerator
 * Генератор кода на C++
 */
class CppGenerator: public Generator
{
protected:
	/** Конструктор
	 * @param os - поток, в который необходимо выдавать шаблон
	 */
	CppGenerator(std::ostream& os): Generator(os) {}
public:
	virtual ~CppGenerator(){}
	virtual void generate(N_Model& m);
	virtual std::string genTypeName(N_Type* t);
	virtual std::string genInterface(N_Interface* c);
	virtual std::string genField(N_Field* f);
	virtual std::string genMethod(N_Class* c, N_Method* m);
	virtual std::string genMethodHeader(N_Method* m, bool pure = false);
	virtual std::string genParameter(N_Param* p);
	virtual std::string genClass(N_Class* c);

	friend class Generator;
};

/** @class JavaGenerator
 * Генератор кода на Java
 */
class JavaGenerator: public Generator
{
protected:
	JavaGenerator(std::ostream& os): Generator(os) {}
public:
	virtual ~JavaGenerator() {}
	virtual void generate(N_Model& m);
	virtual std::string genTypeName(N_Type* t);
	virtual std::string genInterface(N_Interface* c);
	virtual std::string genField(N_Field* f);
	virtual std::string genMethod(N_Class* c, N_Method* m);
	virtual std::string genMethodHeader(N_Method* m, bool pure = false);
	virtual std::string genParameter(N_Param* p);
	virtual std::string genClass(N_Class* c);

	friend class Generator;
};

/** @class PascalGenerator
 * Генератор кода на Pascal
 */
class PascalGenerator: public Generator
{
protected:
	PascalGenerator(std::ostream& os): Generator(os) {}
public:
	virtual ~PascalGenerator(){}
	virtual void generate(N_Model& m);
	virtual std::string genTypeName(N_Type* t);
	virtual std::string genInterface(N_Interface* c);
	virtual std::string genField(N_Field* f);
	virtual std::string genMethod(N_Class* c, N_Method* m);
	virtual std::string genMethodHeader(N_Method* m, bool pure = false);
	virtual std::string genParameter(N_Param* p);
	virtual std::string genClass(N_Class* c);

	friend class Generator;
};

/** @class ObjPascalGenerator
 * Генератор кода на ObjectPascal
 */
class ObjPascalGenerator: public Generator{
protected:
	ObjPascalGenerator(std::ostream& os): Generator(os) {}
public:
	virtual ~ObjPascalGenerator() {}
	virtual void generate(N_Model& m);
	virtual std::string genTypeName(N_Type* t);
	virtual std::string genInterface(N_Interface* c);
	virtual std::string genField(N_Field* f);
	virtual std::string genMethod(N_Class* c, N_Method* m);
	virtual std::string genMethodHeader(N_Method* m, bool pure = false);
	virtual std::string genParameter(N_Param* p);
	virtual std::string genClass(N_Class* c);

	friend class Generator;
};

#endif /* AST_H_ */
