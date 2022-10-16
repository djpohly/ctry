#ifndef _TRY_H
#define _TRY_H

#define CONCAT(x, y) CONCAT_SIMPLE(x, y)
#define CONCAT_SIMPLE(x, y) x ## y

#define try                                                \
	{                                                  \
		__label__ _out;                            \
		int _retval = 0;                           \
		int _returned = 1;                         \
		int _caught = 0;                           \
		auto int try_func();                       \
		_retval = try_func();                      \
		inline int try_func() {                    \
			__label__ _ret;                    \
			if (0) {                           \
		_ret:                                      \
				_returned = 0;             \
				return 0;                  \
			}                                  \
//			{
//				stuff to try
#define catch                                              \
			}                                  \
			goto _ret;                         \
		}                                          \
		auto inline int CONCAT(catch_func_, __LINE__)();              \
		if (_retval && !_caught) {                 \
		_returned = 1;                             \
	 		_caught = 1;                       \
			_retval = CONCAT(catch_func_, __LINE__)(); \
		}                                          \
		inline int CONCAT(catch_func_, __LINE__)() {                  \
			__label__ _ret;                    \
			switch (_retval) {                 \
			_ret:                              \
				_returned = 0;             \
				return 0;                  \
			default:                           \
				_caught = 0;               \
				return _retval;            \
			case
//		     0:
//				exception handler
#define throw \
				do {return _retval;} while (0)
#define finally                                            \
			}                                  \
			goto _ret;                         \
		}                                          \
		                                           \
		{                                          \
			__label__ _ret;                    \
			switch (0) {                       \
		_ret:                                      \
				goto _out;                 \
		default
//		      :
//				cleanup code
//			}
#define endtry                                             \
			goto _ret;                         \
		}                                          \
	_out:                                              \
		if (_returned) return _retval;             \
	} do {} while (0)


// We are intentional about not wrapping any user code in a loop or a switch so
// that attempts to use break or continue will fail to compile rather than
// misbehaving.

#endif
