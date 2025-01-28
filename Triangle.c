//Check a triangle is equilateral,isosceles,scalene.
 #include<stdio.h>
 main()
 {
     float a,b,c;
     printf("Enter Three sides of a Triangle \n");
     scanf("%f%f%f", &a,&b,&c);
    if(a==b && a==c && b==c)
        printf("The Triangle is Equilateral");
    else if(a==b || b==c ||a==c)
            printf("The Triangle is Isosceles");
    else
        printf("The Triangle is Scalene");
    return 0;




 }



