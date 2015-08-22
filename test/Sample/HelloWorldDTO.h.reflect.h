#ifndef __RECLECT_HELLOWORLDDTO_H_REFLECT_H__
#define __RECLECT_HELLOWORLDDTO_H_REFLECT_H__
/* This file was generated on 2015-Aug-13 21:51:07 by Reflect */

#include <Enseed/Reflect/API/Class.h>

namespace reflect {


template<> struct Class<HelloWorldDTO, 0> : public ClassBase<HelloWorldDTO>
{
	typedef HelloWorldDTO type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 2 ;

	struct Fields
	{
		struct self
		{
			typedef self field_type;
			typedef network::uri type;
			typedef const network::uri const_type;
			typedef HelloWorldDTO host_type;
			typedef const HelloWorldDTO const_host_type;
			static const char* name() { return "self"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const network::uri& readRef(const HelloWorldDTO &target) { return target.self; }
			static network::uri* writePtr(HelloWorldDTO *target) { return &target->self; }
		};
		struct hello
		{
			typedef hello field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef HelloWorldDTO host_type;
			typedef const HelloWorldDTO const_host_type;
			static const char* name() { return "hello"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const HelloWorldDTO &target) { return target.hello; }
			static std::string* writePtr(HelloWorldDTO *target) { return &target->hello; }
		};
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::self());
		cb(Fields::hello());
	}
};

template<> struct Field<HelloWorldDTO, 0> : public Class<HelloWorldDTO>::Fields::self{};
template<> struct Field<HelloWorldDTO, 1> : public Class<HelloWorldDTO>::Fields::hello{};

template<> struct SortedField<HelloWorldDTO, 0> : public Class<HelloWorldDTO>::Fields::hello{};
template<> struct SortedField<HelloWorldDTO, 1> : public Class<HelloWorldDTO>::Fields::self{};

} // namespace reflect

#endif // __RECLECT_HELLOWORLDDTO_H_REFLECT_H__
