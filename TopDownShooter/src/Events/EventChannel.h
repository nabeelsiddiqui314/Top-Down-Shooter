#pragma once
#include <tuple>
#include <unordered_map>
#include <functional>
#include <stdint.h>
#include <assert.h>

using Subscription_ID = std::uint32_t;

template <typename T>
using Callback = std::function<void(const T&)>;

template <typename T>
class SubscriptionList {
public:
	SubscriptionList() = default;
	~SubscriptionList() = default;
public:
	Subscription_ID addSubscriber(const Callback<T>& callback) {
		m_callbackMap.emplace(std::make_pair(m_lastID, callback));
		return m_lastID++; // *increments after returning
	}

	void removeAllSubscribers() {
		m_callbackMap.clear();
	}

	void removeSubscriber(Subscription_ID id) {
		auto iterator = m_callbackMap.find(id);
		assert(iterator != m_callbackMap.end() && "Ivalid subscription ID");

		m_callbackMap.erase(iterator);
	}

	void invoke(const T& event) {
		for (auto& subscriber : m_callbackMap) {
			subscriber.second(event);
		}
	}
private:
	Subscription_ID m_lastID = 0;
	std::unordered_map<Subscription_ID, Callback<T>> m_callbackMap;
};

template <typename... Events>
class EventChannel {	
public:
	EventChannel() = default;
	~EventChannel() = default;
public:
	template <typename T>
	Subscription_ID subscribe(const Callback<T>& callback) {
		auto& subscribers = std::get<SubscriptionList<T>>(m_events);
		return subscribers.addSubscriber(callback);
	}

	template <typename T>
	void unsubscribe() {
		auto& subscribers = std::get<SubscriptionList<T>>(m_events);
		subscribers.removeAllSubscribers();
	}

	template <typename T>
	void unsubscribe(Subscription_ID id) {
		auto& subscribers = std::get<SubscriptionList<T>>(m_events);
		subscribers.removeSubscriber(id);
	}

	template <typename T>
	void publish(const T& event) {
		auto& subscribers = std::get<SubscriptionList<T>>(m_events);
		subscribers.invoke(event);
	}
private:
	std::tuple<SubscriptionList<Events>...> m_events;
};