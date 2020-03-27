#pragma once

#ifdef DLL_IMPLEMENT
#define DLL_API _declspec(dllexport)
#else
#define DLL_API _declspec(dllimport)
#endif // DLL_IMPLEMENT


/*
 *				������		����		ƽ��ʱ��			�ȶ���
 *
 * ֱ�Ӳ�������	O(n)		O(n^2)		O(n^2)			�ȶ�
 * �۰��������	O(n)		O(nlog(n))	O(nlog(n))		�ȶ�
 * ϣ������		O(n)		O(n^2)		O(n)~O(n^2)		���ȶ�
 * ѡ������		O(n^2)		O(n^2)		O(n^2)			���ȶ�
 * ð������		O(n)		O(n^2)		O(n^2)			�ȶ�
 * ��������		O(nlog(n))	O(n^2)		O(nlog(n))		���ȶ�
 * ������			O(nlog(n))	O(nlog(n))	O(nlog(n))		���ȶ�
 * �鲢����		O(nlog(n))	O(nlog(n))	O(nlog(n))		�ȶ�
 *
 */

/*
 *	@Brief ֱ�Ӳ�������
 */
extern "C" DLL_API void InsertionSort(int *array, int n);

/*
 *	@Brief ������������
 */
extern "C" DLL_API void SwapInsertionSort(int *array, int n);

/*
 *	@Brief �۰��������
 */
extern "C" DLL_API void BinaryInsertionSort(int *array, int n);

/*
 *	@Brief ϣ������
 */
extern "C" DLL_API void ShellSort(int *array, int n);

/*
 *	@Brief ѡ������
 */
extern "C" DLL_API void SelectSort(int *array, int n);

/*
 *	@Brief ð������
 */
extern "C" DLL_API void BubbleSort(int *array, int n);

/*
 *	@Brief ��������
 */
extern "C" DLL_API void QuicklySort(int *array, int n);

/*
 *	@Brief ������
 */
extern "C" DLL_API void HeapSort(int *array, int n);

/*
 *	@Brief �鲢����
 */
extern "C" DLL_API void MergeSort(int *array, int n);