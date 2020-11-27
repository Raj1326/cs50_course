#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating over the row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over the column of corresponding row
        for (int j = 0; j < width; j++)
        {
            float a = 0;
            //calculating average
            //rounding of to integer
            a = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.000);
            image[i][j].rgbtRed = a;
            image[i][j].rgbtGreen = a;
            image[i][j].rgbtBlue = a;
        }
    }
    return;
}

// Convert image to sepia
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE a[height][width];
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}}, gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    //iterating over the row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over the column of corresponding row
        for (int j = 0; j < width; j++)
        {
            int *gxa;
            gxa = *gx;
            int *gya;
            gya = *gy;
            int x, y, gxred = 0, gxgreen = 0, gxblue = 0, gyred = 0, gygreen = 0, gyblue = 0;
            float red, green, blue;
            //iterating over near by cells
            for (x = i - 1; x <= i + 1; x++)
            {
                for (y = j - 1; y <= j + 1; y++)
                {
                    if (y >= 0 && y < width && x >= 0 && x < height)
                    {
                        //calculating gx values
                        gxred += (*gxa * image[x][y].rgbtRed);
                        gxgreen += (*gxa * image[x][y].rgbtGreen);
                        gxblue += (*gxa * image[x][y].rgbtBlue);
                        //calculating gy values
                        gyred += (*gya * image[x][y].rgbtRed);
                        gygreen += (*gya * image[x][y].rgbtGreen);
                        gyblue += (*gya * image[x][y].rgbtBlue);
                    }
                    gxa++;
                    gya++;
                }
            }
            //using formula gx^2 + gy^2
            red = sqrt(pow(gxred, 2) + pow(gyred, 2));
            green = sqrt(pow(gxgreen, 2) + pow(gygreen, 2));
            blue = sqrt(pow(gxblue, 2) + pow(gyblue, 2));
            //rounding off to appropriate value
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            a[i][j].rgbtRed = (int) round(red);
            a[i][j].rgbtGreen = (int) round(green);
            a[i][j].rgbtBlue = (int) round(blue);

        }
    }
    //loop to copy values to original image

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = a[i][j].rgbtRed;
            image[i][j].rgbtGreen = a[i][j].rgbtGreen;
            image[i][j].rgbtBlue = a[i][j].rgbtBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int red, green, blue;
    //iterating over the row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over the column of corresponding row
        for (int j = 0; j < width / 2; j++)
        {
            //Swap pixels on horizontally opposite sides
            red = image[i][j].rgbtRed ;
            green = image[i][j].rgbtGreen ;
            blue = image[i][j].rgbtBlue ;

            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed ;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

            image[i][width - j - 1].rgbtRed = red;
            image[i][width - j - 1].rgbtGreen = green;
            image[i][width - j - 1].rgbtBlue = blue;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE a[height][width];
    //iterating over the row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over the column of corresponding row
        for (int j = 0; j < width; j++)
        {
            int x, y, sred = 0, sgreen = 0, sblue = 0;
            float p = 0.0;
            //iterating over near by cells
            for (x = i - 1; x <= i + 1; x++)
            {
                if (x >= 0 && x < height)
                {
                    for (y = j - 1; y <= j + 1; y++)
                    {
                        if (y >= 0 && y < width)
                        {
                            sred += image[x][y].rgbtRed;
                            sgreen += image[x][y].rgbtGreen;
                            sblue += image[x][y].rgbtBlue;
                            p++;
                        }
                    }

                }
            }
            //
            a[i][j].rgbtRed = round(sred / p);
            a[i][j].rgbtGreen = round(sgreen / p);
            a[i][j].rgbtBlue = round(sblue / p);
        }
    }
    //loop to values to original image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = a[i][j].rgbtRed;
            image[i][j].rgbtGreen = a[i][j].rgbtGreen;
            image[i][j].rgbtBlue = a[i][j].rgbtBlue;
        }
    }
    return;
}
