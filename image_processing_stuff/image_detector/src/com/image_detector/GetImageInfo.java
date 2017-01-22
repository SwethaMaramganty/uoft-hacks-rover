package com.image_detector;

import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

import javax.imageio.ImageIO;

public class GetImageInfo {
	public static void main(String [] args){
		
		try {
			File file= new File("image.jpg");
			BufferedImage image = ImageIO.read(file);
			
			int width = image.getWidth();
			int height = image.getHeight();
			
			int rgb1 =  image.getRGB(width/2,height/2); 
			int left =  image.getRGB(width/2-5,height/2); 
			int right =  image.getRGB(width/2+5,height/2); 
			int up =  image.getRGB(width/2,height/2-5); 
			int down =  image.getRGB(width/2,height/2+5); 

			
			// Components will be in the range of 0..255:
			int blue = (rgb1 & 0x0000ff);
			int green = (rgb1 & 0x00ff00) >> 8;
			int red = (rgb1 & 0xff0000) >> 16;
			
			ColorUtils cu = new ColorUtils();
			String colourString = cu.getColorNameFromRgb(red, green, blue);
			System.out.println("Colour detected: " + colourString);
			
		} catch (IOException e) {
			System.out.println("Failed");
		}
	}
		
}
