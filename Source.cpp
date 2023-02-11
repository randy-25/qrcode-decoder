#include <opencv2/wechat_qrcode.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    cv::wechat_qrcode::WeChatQRCode decode;
    cv::Mat img = cv::imread("qrCode.png");
    std::vector<cv::Mat> points;
    std::vector<std::string> res = decode.detectAndDecode(img, points);
    if (res.size() > 0)
    {
        for (const auto& value : res)
        {
            std::cout << "Decoded data : " << value << std::endl;
        }
    }
    else {
        std::cout << "QR Code not detected." << std::endl;
    }
    cv::imshow("Image", img);
    cv::waitKey(0);
    return 0;
}