/*
 * StaticFunctionDataAccess.cpp
 *
 *  Created on: Oct 21, 2023
 *      Author: llanyro
 */

#include "StaticFunctionDataAccess.hpp"

namespace llcpp {
namespace static_manager {

namespace monothread {
StaticFunctionData::StaticFunctionData() : SFDAB() {}
StaticFunctionData::~StaticFunctionData() {}
} /* namespace monothread  */

namespace multithread {
StaticFunctionData::StaticFunctionData() : SFDAB(), datamutex() {}
StaticFunctionData::~StaticFunctionData() {}

ll_bool_t StaticFunctionData::add(void* function, void* data) {
	ll_bool_t res = LL_FALSE;
	this->datamutex.lock();
	res = SFDAB::add(function, data);
	this->datamutex.unlock();
	return res;
}
void StaticFunctionData::set(const void* function, void* data) {
	this->datamutex.lock();
	SFDAB::set(function, data);
	this->datamutex.unlock();
}
ll_bool_t StaticFunctionData::get(const void* function, void*& data) {
	ll_bool_t res = LL_FALSE;
	this->datamutex.lock();
	res = SFDAB::get(function, data);
	this->datamutex.unlock();
	return res;
}

} /* namespace multithread  */

} /* namespace static_manager */
} /* namespace llcpp */
