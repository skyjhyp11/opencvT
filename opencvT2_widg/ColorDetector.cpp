//#include "stdafx.h"//window vs
#include "ColorDetector.h"

//C++中成员函数在类里面定义和在类外定义有什么区别:
//在类里定义时，这种函数会被编译器编译成内联函数，在类外定义的函数则不会。
//内联函数的好处是加快程序的运行速度，缺点是会增加程序的尺寸。
//比较推荐的写法是把一个经常要用的而且实现起来比较简单的小型函数放到类里去定义，大型函数最好还是放到类外定义。

////ColorDetector::ColorDetector()
//{
//}

ColorDetector::~ColorDetector()
{
}

int ColorDetector::getDistance(const cv::Vec3b & color) const
{
	//街区距离算法 color---*it-----*image.begin //*:取指针指向的内容
	//return abs(color[0] - target[0]) +
	//	 abs(color[1] - target[1]) +
	//	 abs(color[2] - target[2]);

	//欧拉距离 cv::norm<int, 3>()
	return static_cast<int>(
		cv::norm<int, 3>(cv::Vec3i(color[0] - target[0],
			color[1] - target[1],
			color[2] - target[2])));

	return 0;
}

cv::Mat ColorDetector::process(const cv::Mat & image)
{
	////1.使用BGR颜色空间
    result.create(image.rows, image.cols, CV_8U);//单通道
	////使用迭代器遍历
    cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
    cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
    cv::Mat_<uchar>::iterator itout = result.begin<uchar>();//输出为二值图像

    ////2.使用Lab色彩空间process
    //result.create(image.rows, image.cols, CV_8U);
    //converted.create(image.rows, image.cols,image.type());
    //cv::cvtColor(image, converted,CV_BGR2Lab);//其实只是索引变了
    //cv::Mat_<cv::Vec3b>::const_iterator it = converted.begin<cv::Vec3b>();
    //cv::Mat_<cv::Vec3b>::const_iterator itend = converted.end<cv::Vec3b>();
    //cv::Mat_<char>::iterator itout = result.begin<char>();//输出为二值图像



	for (; it != itend; ++it, ++itout)
	{
		if (getDistance(*it) < minDist)
		{
			*itout = 255;//颜色差值 小于容忍度 像素置255 变白
		}
		else
		{
			*itout = 0;
		}
	}
	return result;  //converted
}


