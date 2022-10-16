#ifndef _TRY_H
#define _TRY_H

#define try                                                \
	{                                                  \
		__label__ _post_catch, _post_finally;      \
		void *_catch = &&_post_catch,              \
		     *_finally = &&_post_finally;          \
		int _retval = 0;                           \
		int _returned = 1;                         \
		inline int try_func() {                    \
			__label__ _ret;                    \
			if (0) {                           \
		_ret:                                      \
				_returned = 0;             \
				return 0;                  \
			}
//			{
//				stuff to try
#define catch \
			}                                  \
			goto _ret;                         \
		}                                          \
		auto inline int catch_func();              \
		{                                          \
			__label__ _catch;                  \
			_catch = &&_catch;                 \
			if (0) {                           \
		_catch:                                    \
				_returned = 1;             \
				_retval = catch_func();    \
				goto _post_catch;          \
			}                                  \
		}                                          \
		                                           \
		inline int catch_func() {                  \
			__label__ _ret;                    \
			if (0) {                           \
		_ret:                                      \
				_returned = 0;             \
				return 0;                  \
			}                                  \
			switch (_retval) {                 \
				default:
//				{
//					exception handler
#define throw \
					do {return _retval;} while (0)
//				}

#define finally                                            \
			}                                  \
			goto _ret;                         \
		}                                          \
		                                           \
		auto inline void finally_func();           \
		{                                          \
			__label__ _finally;                \
			_finally = &&_finally;             \
			if (0) {                           \
		_finally:                                  \
				finally_func();            \
				goto _post_finally;        \
			}                                  \
		}                                          \
		                                           \
		inline void finally_func() {               \
			__label__ _ret;                    \
			if (0) {                           \
		_ret:                                      \
				return;                    \
			}                                  \
			{
//				{
//					cleanup code
//				}
//			}
#define endtry                                             \
			goto _ret;                         \
		}                                          \
		_retval = try_func();                      \
		if (_retval) goto *_catch;                 \
	_post_catch:                                       \
		goto *_finally;                            \
	_post_finally:                                     \
		if (_retval || _returned) return _retval;  \
	} do {} while (0)
// We swallow the semicolon this way rather than enclosing the entire try in a
// do/while block so that attempts to use break or continue will fail to compile
// rather than misbehaving.

#endif
