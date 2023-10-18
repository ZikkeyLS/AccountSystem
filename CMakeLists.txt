cmake_minimum_required (VERSION 3.8)
project(AccountSystem CXX)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

file(GLOB AccountSystemSources "*.cpp" "*.h")
add_executable (AccountSystem ${AccountSystemSources} "Input.h" "AccountSystem.h" "AccountSystem.cpp"  "Utility.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET AccountSystem PROPERTY CXX_STANDARD 20)
endif()
