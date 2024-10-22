/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joamiran <joamiran@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:51:29 by joamiran          #+#    #+#             */
/*   Updated: 2024/10/22 19:54:01 by joamiran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function to calculate the square root of a number
double ft_sqrt(double x)
{
    double  root;
    double  precision;
    
    root = x / 3;
    precision = 0.00001;
    while ((root - x / root) > precision)
        root = (root + x / root) / 2;
    return (root);
}

// function to calculate the mean of a set of numbers
double ft_mean(int *array, int size)
{
    double  mean;
    int     i;
    
    mean = 0;
    i = 0;
    while (i < size)
    {
        mean += array[i];
        i++;
    }
    mean /= size;
    return (mean);
}

// function to calculate the power of a number
double ft_pow(double x, double y)
{
    double  result;
    int     i;
    
    result = 1;
    i = 0;
    while (i < y)
    {
        result *= x;
        i++;
    }
    return (result);
}

// function to calculate the standard deviation of a set of numbers
double ft_std_dev(int *array, int size)
{
    double  mean;
    double  std_dev;
    double  sum;
    int     i;
    
    mean = ft_mean(array, size);
    sum = 0;
    i = 0;
    while (i < size)
    {
        sum += ft_pow(array[i] - mean, 2);
        i++;
    }
    std_dev = ft_sqrt(sum / size);
    return (std_dev);
}

// function to calculate the median of a set of numbers
double ft_median(int *array, int size)
{
    double  median;
    int     i;
    
    median = 0;
    i = 0;
    while (i < size)
    {
        median += array[i];
        i++;
    }
    median /= size;
    return (median);
}
