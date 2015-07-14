#!/usr/bin/python
#-*-coding:utf-8-*-

# #  FileName    : BubbleSort.py
# #  Author      : BaoBao SHI <sbbmym@icloud.com>
# #  Created     : Tue July 14 18:48 2015 by BaoBao SHI
# #  Copyright   : Feather (c) 2015
# #  Description : 冒泡排序
# #  Time-stamp: <2015-07-14 19:06>


def BubbleSort(sort_list):
    iter_len = len(sort_list)
    if iter_len < 2:
        return sort_list
    
    for i in range(iter_len - 1):
        for j in range(iter_len - i - 1):
            if sort_list[j] > sort_list[j + 1]:
                sort_list[j], sort_list[j + 1] = sort_list[j + 1], sort_list[j ]
                
    return sort_list    


if __name__ == '__main__':
    sort_list = [20, 56, 89, 54, 14, 16, 64, 56]
    BubbleSort(sort_list)
    print sort_list
