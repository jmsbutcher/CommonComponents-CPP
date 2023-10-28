#pragma once

#include <map>
#include <memory>
#include <string>

#define DLL __declspec(dllexport)


template <typename T>
 class SimpleContainer {

public:
	// Add an item to the container.
	// The item can then be accessed either by name or by ID.
	// If you do not specify an ID, the container will assign a default ID
	// that starts at 0 and increments by 1 for each item you add.
	DLL void Add(std::shared_ptr<T> item, std::string item_name, int id = -1);

	// Retrieve item by name. Throws std::out_of_range exception if not found.
	DLL std::shared_ptr<T> Get(std::string item_name);

	// Retrieve item by ID. Throws std::out_of_range exception if not found.
	DLL std::shared_ptr<T> Get(int item_id);

private:
	std::map<int, std::shared_ptr<T>> mapIDToItem;
	std::map<std::string, std::shared_ptr<T>> mapNameToItem;

	int idCounter = 0;

};


 template<typename T>
 inline void SimpleContainer<T>::Add(std::shared_ptr<T> item, std::string item_name, int id) {
	 if (id == -1) {
		 mapIDToItem[idCounter] = item;
		 idCounter++;
	 }
	 else
		 mapIDToItem[id] = item;

	 mapNameToItem[item_name] = item;
 }


 template<typename T>
 inline std::shared_ptr<T> SimpleContainer<T>::Get(std::string item_name) {
	 return mapNameToItem.at(item_name);
 }


 template<typename T>
 inline std::shared_ptr<T> SimpleContainer<T>::Get(int item_id) {
	 return mapIDToItem.at(item_id);
 }


