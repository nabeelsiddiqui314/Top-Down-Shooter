#pragma once
#include <vector>
#include <functional>

template <typename... Events>
class EventChannel {
private:
	template <typename T>
	using Callback = std::function<void(const T&)>;

	template <typename T>
	using SubscriptionList = std::vector<Callback<T>>;
public:
	EventChannel() = default;
	~EventChannel() = default;
public:
	template <typename T>
	void subscribe(const Callback<T>& callback) {
		auto& subscriber = std::get<SubscriptionList<T>>(m_events);
		subscriber.emplace_back(callback);
	}

	template <typename T>
	void broadcast(const T& event) {
		auto& subscribers = std::get<SubscriptionList<T>>(m_events);
		for (auto& subscriber : subscribers) {
			subscriber(event);
		}
	}
private:
	std::tuple<SubscriptionList<Events>...> m_events;
};