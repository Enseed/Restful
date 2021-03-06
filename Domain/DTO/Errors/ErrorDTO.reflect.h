#ifndef __RECLECT_ERRORDTO_REFLECT_H__
#define __RECLECT_ERRORDTO_REFLECT_H__
/* This file was generated on 2015-Sep-19 19:18:01 by Enseed Reflect */

#include <Reflect/Class.h>

namespace reflect {


template<> struct Class<ErrorDTO, 0> : public ClassBase<ErrorDTO>
{
	typedef ErrorDTO type;
	static constexpr int parent_count = 0;
	static constexpr int field_count = 6 ;
	static constexpr const char* name() { return "ErrorDTO"; }

	struct Fields
	{
		struct time
		{
			typedef time field_type;
			typedef boost::posix_time::ptime type;
			typedef const boost::posix_time::ptime const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "time"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::posix_time::ptime& readRef(const ErrorDTO &target) { return target.time; }
			static boost::posix_time::ptime* writePtr(ErrorDTO *target) { return &target->time; }
		};
		struct id
		{
			typedef id field_type;
			typedef boost::uuids::uuid type;
			typedef const boost::uuids::uuid const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "id"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::uuids::uuid& readRef(const ErrorDTO &target) { return target.id; }
			static boost::uuids::uuid* writePtr(ErrorDTO *target) { return &target->id; }
		};
		struct error_type
		{
			typedef error_type field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "error_type"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const ErrorDTO &target) { return target.error_type; }
			static std::string* writePtr(ErrorDTO *target) { return &target->error_type; }
		};
		struct message
		{
			typedef message field_type;
			typedef std::string type;
			typedef const std::string const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "message"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const std::string& readRef(const ErrorDTO &target) { return target.message; }
			static std::string* writePtr(ErrorDTO *target) { return &target->message; }
		};
		struct stack
		{
			typedef stack field_type;
			typedef boost::optional<std::vector<std::string> > type;
			typedef const boost::optional<std::vector<std::string> > const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "stack"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const boost::optional<std::vector<std::string> >& readRef(const ErrorDTO &target) { return target.stack; }
			static boost::optional<std::vector<std::string> >* writePtr(ErrorDTO *target) { return &target->stack; }
		};
		struct cause
		{
			typedef cause field_type;
			typedef seed::CountPtr<ErrorDTO> type;
			typedef const seed::CountPtr<ErrorDTO> const_type;
			typedef ErrorDTO host_type;
			typedef const ErrorDTO const_host_type;
			static const char* name() { return "cause"; }
			static constexpr reflect::Visibility::Value visibility = reflect::Visibility::PUBLIC;
			static const seed::CountPtr<ErrorDTO>& readRef(const ErrorDTO &target) { return target.cause; }
			static seed::CountPtr<ErrorDTO>* writePtr(ErrorDTO *target) { return &target->cause; }
		};
	};

	template<typename CB> static void visitParents(CB &cb = CB())
	{
	}

	template<typename CB> static void visitFields(CB &cb = CB())
	{
		cb(Fields::time());
		cb(Fields::id());
		cb(Fields::error_type());
		cb(Fields::message());
		cb(Fields::stack());
		cb(Fields::cause());
	}
};

template<> struct Field<ErrorDTO, 0> : public Class<ErrorDTO>::Fields::time{};
template<> struct Field<ErrorDTO, 1> : public Class<ErrorDTO>::Fields::id{};
template<> struct Field<ErrorDTO, 2> : public Class<ErrorDTO>::Fields::error_type{};
template<> struct Field<ErrorDTO, 3> : public Class<ErrorDTO>::Fields::message{};
template<> struct Field<ErrorDTO, 4> : public Class<ErrorDTO>::Fields::stack{};
template<> struct Field<ErrorDTO, 5> : public Class<ErrorDTO>::Fields::cause{};

template<> struct SortedField<ErrorDTO, 0> : public Class<ErrorDTO>::Fields::cause{};
template<> struct SortedField<ErrorDTO, 1> : public Class<ErrorDTO>::Fields::error_type{};
template<> struct SortedField<ErrorDTO, 2> : public Class<ErrorDTO>::Fields::id{};
template<> struct SortedField<ErrorDTO, 3> : public Class<ErrorDTO>::Fields::message{};
template<> struct SortedField<ErrorDTO, 4> : public Class<ErrorDTO>::Fields::stack{};
template<> struct SortedField<ErrorDTO, 5> : public Class<ErrorDTO>::Fields::time{};

} // namespace reflect

#endif // __RECLECT_ERRORDTO_REFLECT_H__
