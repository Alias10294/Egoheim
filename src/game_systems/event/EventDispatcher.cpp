#include "EventDispatcher.hpp"

EventDispatcher::~EventDispatcher()
{}

void EventDispatcher::Unsubscribe(const SubscriptionToken& token)
{
    auto typeIt = m_subscriptions.find(token.typeIndex);
    if (typeIt == m_subscriptions.end())
        return;
    
    auto& subscriptions = typeIt->second;
    auto subIt = std::remove_if
    (
        subscriptions.begin(), 
        subscriptions.end(), 
        [token](const std::unique_ptr<ISubscription>& subscription)
        {
            return subscription->GetId() == token.index;
        }
    );
    if (subIt == subscriptions.end())
        return;
    
    subscriptions.erase(subIt, subscriptions.end());
}

void EventDispatcher::Dispatch(const Event& event) const
{
    std::visit
    (
        [this, &event](const auto& specificEvent)
        {
            using EventType = std::decay_t<decltype(specificEvent)>;
            const auto subIt = m_subscriptions.find(std::type_index(typeid(EventType)));
            if (subIt == m_subscriptions.end())
                return;
            
            const auto& subscriptions = subIt->second;
            for (const auto& subscription : subscriptions)
            {
                if (subscription->IsFilter(event))
                    subscription->OnCallback(event);
            }
        }, 
        event
    );
}