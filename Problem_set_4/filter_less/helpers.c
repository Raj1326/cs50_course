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
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    //iterating over the row of image
    for (int i = 0; i < height; i++)
    {
        //iterating over the column of corresponding row
        for (int j = 0; j < width; j++)
        {
            int sepiaRed, sepiaGreen, sepiaBlue;
            //Calculating values according to sepia algorithm
            sepiaRed = nearbyint(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = nearbyint(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = nearbyint(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            //converting to invalid to valid values
            if (sepiaRed > 254)
            {
                image[i][j].rgbtRed = 255;
            }
            else if (sepiaRed < 1)
            {
                image[i][j].rgbtRed = 0;
            }
            else
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            if (sepiaGreen > 254)
            {
                image[i][j].rgbtGreen = 255;
            }
            else if (sepiaGreen < 1)
            {
                image[i][j].rgbtGreen = 0;
            }
            else
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            if (sepiaBlue > 254)
            {
                image[i][j].rgbtBlue = 255;
            }
            else if (sepiaBlue < 1)
            {
                image[i][j].rgbtBlue = 0;
            }
            else
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
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
