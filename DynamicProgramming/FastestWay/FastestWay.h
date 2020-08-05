﻿#pragma once

// 动态规划	工厂装配线

// e1,e2是两条装配生产线的输入消耗，x1,x2是输出消耗
// a1[i]是1号生产线的第i个装配站消耗，a2[i]是2号生产线的第i个装配站消耗（i: 1 ~ n）
// t1[i]记录了1号生产线的第i个装配站转移到2号生产线的第i+1个装配站的消耗（i: 1 ~ n-1）
// t2[i]记录了2号生产线的第i个装配站转移到1号生产线的第i+1个装配站的消耗（i: 1 ~ n-1）

// f1[j]记录一个底盘从起点到1号生产线的第j个装配站的最快时间
// f2[j]记录一个底盘从起点到2号生产线的第j个装配站的最快时间

// L1[j]记录了底盘最快到达1号生产线的第j个装配站时，前一个装配站的生产线编号（1或2）
// L2[j]记录了底盘最快到达2号生产线的第j个装配站时，前一个装配站的生产线编号（1或2）

// n为装配站数
// L表示底盘从最后一个装配站出来时的生产线编号

void fastest_way(int e1, int e2, int x1, int x2, int *a1, int *a2, int *t1, int *t2, int *f1, int *f2, int *L1, int *L2, int n, int &L);
