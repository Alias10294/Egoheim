#ifndef EVENTDISPATCHER_HPP
#define EVENTDISPATCHER_HPP

#include <unordered_map>
#include <vector>
#include <functional>
#include <typeindex>
#include <memory>
#include <algorithm>

#include "Event.hpp"

class EventDispatcher
{
public: 
    ~EventDispatcher(); 

    template<typename EventType> 
    using Filter = std::function<bool(const EventType&)>;
    template<typename EventType> 
    using Callback = std::function<void(const EventType&)>;

    struct SubscriptionToken
    {
        const std::type_index typeIndex;
        const std::size_t index;
    };

    template<typename EventType>
    const SubscriptionToken Subscribe(Filter<EventType> filter, Callback<EventType> callback) 
    {
        const SubscriptionToken token = 
        { 
            std::type_index(typeid(EventType)), 
            m_subscriptionCount 
        };
        auto subscription = std::make_unique<Subscription<EventType>>(filter, callback, m_subscriptionCount++);
        m_subscriptions[token.typeIndex].push_back(subscription);

        return token;
    }

    void Unsubscribe(const SubscriptionToken& token);

    void Dispatch(const Event& event) const;
    
private:
    class ISubscription
    {
    public:
        virtual ~ISubscription() = default;

        [[nodiscard]] virtual const std::size_t GetId() const = 0;
        
        [[nodiscard]] virtual bool IsFilter(const Event& event) const = 0;
        virtual void OnCallback(const Event& event) const = 0;

    };
    template <typename EventType>
    class Subscription : public ISubscription
    {
    public:
        Subscription(Filter<EventType> filter, Callback<EventType> callback, const std::size_t id)
          : m_id(id), m_filter(std::move(filter)), m_callback(std::move(callback))
        { }
        ~Subscription()
        { }
        
        [[nodiscard]] virtual const std::size_t GetId() const override
        {
            return m_id;            
        } 

        [[nodiscard]] virtual bool IsFilter(const Event& event) const override
        {
            if (const auto& specificEvent = std::get_if<EventType>(&event))
                return m_filter(*specificEvent);
            return false;
        }
        virtual void OnCallback(const Event& event) const override
        {
            if (const auto& specificEvent = std::get_if<EventType>(&event))
                m_callback(*specificEvent);
        }
    
    private:
        const std::size_t m_id; 

        Filter<EventType> m_filter;
        Callback<EventType> m_callback;
    };
    
    std::unordered_map<std::type_index, std::vector<std::unique_ptr<ISubscription>>> m_subscriptions{};
    std::size_t m_subscriptionCount{0};

};

#endif