function(cond_add_subdirectory target_name path)

if (NOT TARGET ${target_name} AND EXISTS ${path})
	add_subdirectory(${path})
else ()
	if (NOT EXISTS ${path})
		message(WARNING "Directory ${path} not present, target ${target_name} missing!")
	endif()
endif()

endfunction()
