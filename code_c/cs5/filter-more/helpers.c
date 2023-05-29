#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float res = (image[y][x].rgbtBlue + image[y][x].rgbtGreen + image[y][x].rgbtRed);
            image[y][x].rgbtBlue = round(res / 3);
            image[y][x].rgbtGreen = round(res / 3);
            image[y][x].rgbtRed = round(res / 3);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int x = 0; x < width / 2; x++)
    {
        for (int y = 0; y < height; y++)
        {
            RGBTRIPLE tmp = image[y][x];
            image[y][x] = image[y][width - x - 1];
            image[y][width - x - 1] = tmp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            int count = 0;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height)
                    {
                        blue = blue + image[y + j][x + i].rgbtBlue;
                        green = green + image[y + j][x + i].rgbtGreen;
                        red = red + image[y + j][x + i].rgbtRed;
                        count++;
                    }
                }

            }
            copy[y][x].rgbtBlue = round(blue / count);
            copy[y][x].rgbtGreen = round(green / count);
            copy[y][x].rgbtRed = round(red / count);
        }
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[y][x] = copy[y][x];
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gx[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};
    int gy[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    RGBTRIPLE copy[height][width];
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            float gx_red = 0;
            float gx_green = 0;
            float gx_blue = 0;
            float gy_red = 0;
            float gy_green = 0;
            float gy_blue = 0;
            int count = 0;
            for (int i = -1; i < 2; i++)
            {
                for (int j = -1; j < 2; j++)
                {
                    if (x + i >= 0 && x + i < width && y + j >= 0 && y + j < height)
                    {
                        gx_blue = gx_blue + image[y + j][x + i].rgbtBlue * gx[count];
                        gx_green = gx_green + image[y + j][x + i].rgbtGreen * gx[count];
                        gx_red = gx_red + image[y + j][x + i].rgbtRed * gx[count];
                        gy_blue = gy_blue + image[y + j][x + i].rgbtBlue * gy[count];
                        gy_green = gy_green + image[y + j][x + i].rgbtGreen * gy[count];
                        gy_red = gy_red + image[y + j][x + i].rgbtRed * gy[count];
                    }
                    count++;
                }

            }
            int red = round(sqrt(gy_red * gy_red + gx_red * gx_red));
            int blue = round(sqrt(gy_blue * gy_blue + gx_blue * gx_blue));
            int green = round(sqrt(gy_green * gy_green + gx_green * gx_green));

            if (red <= 255 && red > 0) copy[y][x].rgbtRed = red;
            else if (red > 255) copy[y][x].rgbtRed = 255;
            else if (red < 0) copy[y][x].rgbtRed = 0;

            if (blue <= 255 && blue > 0) copy[y][x].rgbtBlue = blue;
            else if (blue > 255) copy[y][x].rgbtBlue = 255;
            else if (blue < 0) copy[y][x].rgbtBlue = 0;

            if (green <= 255 && green > 0) copy[y][x].rgbtGreen = green;
            else if (green > 255) copy[y][x].rgbtGreen = 255;
            else if (green < 0) copy[y][x].rgbtGreen = 0;

        }
    }

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            image[y][x] = copy[y][x];
        }
    }

    return;
}
