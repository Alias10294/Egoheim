#ifndef INPUT_HPP
#define INPUT_HPP

#include <type_traits>
#include <string>

template <typename InputEnumType, typename DerivedInputType>
class Input
{
public:
    Input(const InputEnumType type, const long value = 0L)
        : m_type(type), m_value(value)
    {
        static_assert(std::is_enum_v<InputEnumType>);
        static_assert(std::is_base_of_v<Input<InputEnumType, DerivedInputType>, DerivedInputType>);
        static_assert(std::is_convertible_v<decltype(DerivedInputType::GetConfigFileImpl()), std::string>);
        static_assert(std::is_convertible_v<decltype(DerivedInputType::InputEnumToStringImpl(std::declval<InputEnumType>())), std::string>);
        static_assert(std::is_convertible_v<decltype(DerivedInputType::StringToInputEnumImpl(std::declval<std::string>())), InputEnumType>);
    }
    virtual ~Input() = default;

    [[nodiscard]] static const std::string GetConfigFile()
    {
        return DerivedInputType::GetConfigFileImpl();
    }

    [[nodiscard]] static const std::string InputEnumToString(const InputEnumType inputEnum)
    {
        return DerivedInputType::InputEnumToStringImpl(inputEnum);
    }
    [[nodiscard]] static const InputEnumType StringToInputEnum(const std::string& inputEnumStr)
    {
        return DerivedInputType::StringToInputEnumImpl(inputEnumStr);
    }

    [[nodiscard]] const long GetValue() const noexcept
    {
        return m_value;
    }

protected:
    InputEnumType m_type; 
    long m_value; 
};

#endif