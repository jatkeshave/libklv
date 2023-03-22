include_guard(GLOBAL)

function(option_string VARIABLE HELP_TEXT DEFAULT_VALUE)
  # todo: enabled assertion for passed arguments
  if (EXISTS ${VARIABLE})
    return()
  endif()

  set(${VARIABLE} ${DEFAULT_VALUE} CACHE STRING ${HELP_TEXT} FORCE)
endfunction()

