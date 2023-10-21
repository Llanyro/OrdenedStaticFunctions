/*
 * StaticFunctionDataAccess.hpp
 *
 *  Created on: Oct 21, 2023
 *      Author: llanyro
 */
#ifndef LLCPP_STATICFUNCTIONDATAACCESS_HPP_
#define LLCPP_STATICFUNCTIONDATAACCESS_HPP_

#include "StaticFunctionDataAccessBase.hpp"

#include <Singleton.hpp>

#include <mutex>
#include <map>

namespace llcpp {
namespace static_manager {

template<class T>
using Singleton = header::singleton::static_::Singleton<T>;

namespace monothread {
/*
*	Transforms SFDAB into an Singleton
*	
*	You can use this in multithread programs if you are not going to delete any data(function)
*/
class LL_SHARED_LIB StaticFunctionData : public SFDAB, public Singleton<StaticFunctionData> {
	#pragma region Singleton
	private:
		friend class Singleton<StaticFunctionData>;
		StaticFunctionData();
		~StaticFunctionData();
	#pragma endregion
};
} /* namespace monothread  */

namespace multithread {

/*
*	Transforms SFDAB into an Singleton
*	Also add a mutex to make thread safe
*
*	Remember that you can use monothread mode if you are not going to delete any data(function)
*/
class LL_SHARED_LIB StaticFunctionData : public SFDAB, public Singleton<StaticFunctionData> {
	#pragma region Singleton
	private:
		friend class Singleton<StaticFunctionData>;
		StaticFunctionData();
		~StaticFunctionData();
	#pragma endregion
	private:
		std::mutex datamutex;
	public:
		// Adds to manager a function to indentify and data to return when requested
		virtual ll_bool_t add(void* function, void* data) override;
		/*
		*	If function exist, data will be overrided
		*	If not, data will be setted as add()
		*/
		virtual void set(const void* function, void* data) override;;
		/*
		*	Returns data for function requested via parameter
		*	If function returns true function was found
		*/
		virtual ll_bool_t get(const void* function, void*& data) override;;
};

} /* namespace multithread  */

} /* namespace static_manager */
} /* namespace llcpp */

#endif // !LLCPP_STATICFUNCTIONDATAACCESS_HPP_
