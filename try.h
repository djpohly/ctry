#ifndef _TRY_H
#define _TRY_H

#define try                                                \
	{                                                  \
		__label__ _post_catch, _post_finally;      \
		void *_catch = &&_post_catch,              \
		     *_finally = &&_post_finally;          \
		int _retval = 0;                           \
		int _returned = 1;                         \
		int _broke = 1;                            \
		int _contd = 0;                            \
		inline int try_func() {                    \
			__label__ _ret, _do;               \
			if (0) {                           \
		_ret:                                      \
				_returned = 0;             \
				return 0;                  \
			}                                  \
			for (; !_contd; _contd = 1) {
//				{
//					stuff to try
#define catch \
				}                          \
				_broke = 0;                \
				break;                     \
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
			__label__ _ret, _do;               \
			if (0) {                           \
		_ret:                                      \
				_returned = 0;             \
				return 0;                  \
			}                                  \
			while (1) {                        \
				{
//					{
//						exception handler
#define throw \
						do {return _retval;} while (0)
//					}

#define finally                                            \
				}                          \
				_broke = 0;                \
				break;                     \
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
			__label__ _ret, _do;               \
			if (0) {                           \
		_ret:                                      \
				return;                    \
			}                                  \
			while (1) {                        \
				{
//					{
//						cleanup code
//					}
//				}
#define _endtry_start                                      \
				_broke = 0;                \
				break;                     \
			}                                  \
			goto _ret;                         \
		}                                          \
		_retval = try_func();                      \
		if (_retval) fprintf(stderr, "  try: \e[30;41;1merror\e[m\n"); \
		else if (_returned) fprintf(stderr, "  try: \e[30;42;1mreturn\e[m\n"); \
		else if (_contd) fprintf(stderr, "  try: \e[30;46;1mcontinue\e[m\n"); \
		else if (_broke) fprintf(stderr, "  try: \e[30;44;1mbreak\e[m\n"); \
		else fprintf(stderr, "  try: normal\n"); \
		if (_retval) goto *_catch;                 \
	_post_catch:                                       \
		goto *_finally;                            \
	_post_finally:                                     \
		if (_retval || _returned) return _retval;
#define _endtry_in_loop                                    \
		if (_contd) continue;                      \
		if (_broke) break;
#define _endtry_end                                        \
	} do {} while (0)

#define endtry _endtry_start _endtry_end
#define endtry_loop _endtry_start _endtry_in_loop _endtry_end

#endif
