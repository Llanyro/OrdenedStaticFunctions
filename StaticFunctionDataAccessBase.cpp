/*
 * StaticFunctionDataAccessBase.cpp
 *
 *  Created on: Oct 21, 2023
 *      Author: llanyro
 */

#include "StaticFunctionDataAccessBase.hpp"

namespace llcpp {
namespace static_manager {

StaticFunctionDataAccessBase::StaticFunctionDataAccessBase() : data() {}
StaticFunctionDataAccessBase::~StaticFunctionDataAccessBase() {}

ll_bool_t StaticFunctionDataAccessBase::add(void* function, void* data) {
	if (this->data.find(function) != this->data.end()) return LL_FALSE;
	this->data.insert({ function, data });
	return LL_TRUE;
}
void StaticFunctionDataAccessBase::set(const void* function, void* data) {
	auto it = this->data.find(function);
	if (it != this->data.end())
		it->second = data;
	else this->data.insert({ function, data });
}
ll_bool_t StaticFunctionDataAccessBase::get(const void* function, void*& data) {
	auto it = this->data.find(function);
	if (it == this->data.end()) return LL_FALSE;
	data = it->second;
	return LL_TRUE;
}

} /* namespace static_manager */
} /* namespace llcpp */
