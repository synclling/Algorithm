#pragma once

#ifdef DLL_IMPLEMENT
#define DLL_API _declspec(dllexport)
#else
#define DLL_API _declspec(dllimport)
#endif // DLL_IMPLEMENT


/*
 *				最好情况		最坏情况		平均时间			稳定性
 *
 * 直接插入排序	O(n)		O(n^2)		O(n^2)			稳定
 * 折半插入排序	O(n)		O(nlog(n))	O(nlog(n))		稳定
 * 希尔排序		O(n)		O(n^2)		O(n)~O(n^2)		不稳定
 * 选择排序		O(n^2)		O(n^2)		O(n^2)			不稳定
 * 冒泡排序		O(n)		O(n^2)		O(n^2)			稳定
 * 快速排序		O(nlog(n))	O(n^2)		O(nlog(n))		不稳定
 * 堆排序			O(nlog(n))	O(nlog(n))	O(nlog(n))		不稳定
 * 归并排序		O(nlog(n))	O(nlog(n))	O(nlog(n))		稳定
 *
 */

/*
 *	@Brief 直接插入排序
 */
extern "C" DLL_API void InsertionSort(int *array, int n);

/*
 *	@Brief 交换插入排序
 */
extern "C" DLL_API void SwapInsertionSort(int *array, int n);

/*
 *	@Brief 折半插入排序
 */
extern "C" DLL_API void BinaryInsertionSort(int *array, int n);

/*
 *	@Brief 希尔排序
 */
extern "C" DLL_API void ShellSort(int *array, int n);

/*
 *	@Brief 选择排序
 */
extern "C" DLL_API void SelectSort(int *array, int n);

/*
 *	@Brief 冒泡排序
 */
extern "C" DLL_API void BubbleSort(int *array, int n);

/*
 *	@Brief 快速排序
 */
extern "C" DLL_API void QuicklySort(int *array, int n);

/*
 *	@Brief 堆排序
 */
extern "C" DLL_API void HeapSort(int *array, int n);

/*
 *	@Brief 归并排序
 */
extern "C" DLL_API void MergeSort(int *array, int n);