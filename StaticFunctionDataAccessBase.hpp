/*
 * StaticFunctionDataAccessBase.hpp
 *
 *  Created on: Oct 21, 2023
 *      Author: llanyro
 */
#ifndef LLCPP_STATICFUNCTIONDATAACCESSBASE_HPP_
#define LLCPP_STATICFUNCTIONDATAACCESSBASE_HPP_

#include <llanytypeslib.hpp>

#include <map>

namespace llcpp {
namespace static_manager {

class StaticFunctionDataAccessBase {
	private:
		std::map<const void*, void*> data;
	public:
		StaticFunctionDataAccessBase();
		~StaticFunctionDataAccessBase();
		// Adds to manager a function to indentify and data to return when requested
		virtual ll_bool_t add(void* function, void* data);
		/*
		*	If function exist, data will be overrided
		*	If not, data will be setted as add()
		*/
		virtual void set(const void* function, void* data);
		/*
		*	Returns data for function requested via parameter
		*	If function returns true function was found
		*/
		virtual ll_bool_t get(const void* function, void*& data);
};

using SFDAB = StaticFunctionDataAccessBase;

} /* namespace static_manager */
} /* namespace llcpp */

#endif // !LLCPP_STATICFUNCTIONDATAACCESSBASE_HPP_
