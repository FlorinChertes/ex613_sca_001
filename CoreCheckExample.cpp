// CoreCheckExample.cpp
// Add CppCoreCheck package and enable code analysis in build for warnings.

#include <cassert>
#include <iostream>

int null_deref(int x)
{
	int* p = nullptr;

	if (x)
	{
		return *p + 13;
	}
	else
	{
		return 47;
	}
}

int div_by_zero(int x)
{
	if(x)
	{
		return 13 / 0;
	}
	else
	{
		return 47;
	}
}

int un_init(int x)
{
	int u;
	if (x)
	{
		return u + 13;
	}
	else
	{
		return 47;
	}
}

int overflow (int x)
{
	if (x + 1 < x )
	{
		return 13;
	}
	else
	{
		return 47;
	}
}
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void test_utils_024()
{
	std::cout << "*** test utils 024 ***" << std::endl;
	int ret_val = 0;

	ret_val = un_init(1);
	std::cout << "ret val un init = " << ret_val << std::endl;

	ret_val = overflow(1);
	std::cout << "ret val overflow = " << ret_val << std::endl;

	ret_val = div_by_zero(1);
	std::cout << "ret val div by null = " << ret_val << std::endl;

	ret_val = null_deref(1);
	std::cout << "ret val null deref = " << ret_val << std::endl;
}

int main()
{
    int arr[10];           // warning C26494
    int* p = arr;          // warning C26485

    //[[gsl::suppress(bounds.1)]] // This attribute suppresses Bounds rule #1
    {
        int* q = p + 1;    // warning C26481 (suppressed)
        p = q++;           // warning C26481 (suppressed)
    }

    test_utils_024();

    return 0;
}
