#include <stdio.h>

#define try                                              \
	{                                                \
		__label__ _post_catch, _post_finally;    \
		void *_catch = &&_post_catch,            \
		     *_finally = &&_post_finally;        \
		int _retval = 0;                         \
		int try_func() {                         \
			__label__ _ret;                  \
			if (0) {                         \
		_ret:                                    \
				return 0;                \
			}

			/* stuff to try */

#define catch \
			goto _ret;                       \
		}                                        \
		auto int catch_func();                   \
		{                                        \
			__label__ _catch;                \
			_catch = &&_catch;               \
			if (0) {                         \
		_catch:                                  \
				_retval = catch_func();  \
				goto _post_catch;        \
			}                                \
		}                                        \
		                                         \
		int catch_func() {                       \
			__label__ _ret;                  \
			if (0) {                         \
		_ret:                                    \
				return 0;                \
			}

			/* exception handler */

#define throw           return _retval

#define finally                                          \
			goto _ret;                       \
		}                                        \
		                                         \
		auto void finally_func();                \
		{                                        \
			__label__ _finally;              \
			_finally = &&_finally;           \
			if (0) {                         \
		_finally:                                \
				finally_func();          \
				goto _post_finally;      \
			}                                \
		}                                        \
		                                         \
		void finally_func() {                    \
			__label__ _ret;                  \
			if (0) {                         \
		_ret:                                    \
				return;                  \
			}

			/* to be run in any case */

#define endtry                                           \
			goto _ret;                       \
		}                                        \
		_retval = try_func();                    \
		if (_retval) goto *_catch;               \
	_post_catch:                                     \
		goto *_finally;                          \
	_post_finally:                                   \
		if (_retval) return _retval;             \
	}                                                \
	do {} while (0)

void nothing(void) {}

int main(void)
{
	int i = 11, j = 20;

	printf("before\n");

	try {
		try {
			if (i > 10) {
				printf("error: i > 10\n");
				return 1;
			}
		}
		catch {
			printf("inner catch\n");
			throw;
		}
		finally printf("inner finally\n");
		endtry;

		printf("the rest\n");
	}
	catch printf("catch %d %d\n", i, j);
	finally printf("outer finally\n");
	endtry;

	return 0;
}

/* int _defer_6(int i, int j) { */
/* 	printf("foo %d\n", i * j); */
/* 	return 1; */
/* } */
