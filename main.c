#include <stdio.h>

void display()
{
    printf("\n");
    printf("\n************************************************************************************************************************************************************");
    printf("\n*               *                  *                *                      *                       *                 *            *                        *");
    printf("\n*   Serial no   *   Product Name   *   Product Id   *   Product Quantity   *   Rate per unit(tk)   *   Discount(%%)   *   Vat(%%)   *   Price per unit(tk)   *");
    printf("\n*               *                  *                *                      *                       *                 *            *                        *");
    printf("\n************************************************************************************************************************************************************");
    printf("\n");

}

int main()
{
    float prd_rate[10000],prd_disc[10000],prd_price[10000],vat,prd_to_buy_price=0,total_purchase=0; ///product_rate,product_discount,product_price,vat,the price for buying the same product, total purchase amount
    int sl_no=0,prd_id[10000],prd_qty[10000],option,prd_num,i=0,j=0,k=0,l=0,m=0,prd_qty_factor=0,total_prd=0,total=0,prd_change_num,prd_id_num,num_change,prd_id_delete,prd_delete_factor[10000],prd_to_buy_id,prd_to_buy_qty=0,sale[10000],sale_count,low_sale_count;
    /*serial_number, product_id,product_quantity,product Input,product_number, i (for different types only for input), j (loop iterator for other loops),
    total_products ,total product complimentary, how many products to change, which product id needs to be changed , the number corresponding item ,
     product id to delete, the factor that defines if the product will be deleted or not, the product id to buy, the amount to buy ,
    */

    char prd_name[1000][1000],temp,more_purchase_factor,low_qty_factor,vat_factor; /*product_name,temp statement to clear buffer (when taken as sentence and before that an integer is taken as input) ,
     defines whether to buy more, the factor to define if the buyer will buy or not  */
    /*Title*/
    printf("\n\t\t\t\t=========================================================\n\t\t\t\t\t\t  INVENTORY software\n\t\t\t\t=========================================================");



vat_label:
    printf("\n\n\tWill Your Shop Have VAT?(Y/N)");
    vat_factor=getchar();

    if(vat_factor=='y' || vat_factor=='Y')
    {
        printf("\n\n\tThe Amount of Vat of Your Shop \t");
        scanf("%f",&vat);

    }


    else if(vat_factor=='n' || vat_factor=='N')
    {
        vat=0;
    }

    else
    {
        getchar();
        printf("\nInvalid Input");
        goto vat_label;
    }

option_selector_label: ///taking the options again and again unless exiting

    prd_to_buy_price=0;
    total_purchase=0;

    printf("\n\n");

    total=total_prd; ///static value for the total products

    /*Title*/
    printf("\n\t\t\t\t=========================================================\n\t\t\t\t\t\t  INVENTORY software\n\t\t\t\t=========================================================");


    /*Options Selector*/
    printf("\n\n\nSelect Your Choice:\n 1)Product Input\n 2)Edit Product\n 3)Delete Product\n 4)Display Available Products\n 5)Make A Purchase\n 6)Heighest Sale\n 7)Lowest Sale\n 8)Zero Quantity\n 9)Exit\n 10)Show All Products\n 11)Edit the VAT ");

    /*User's Option Input*/
    printf("\n\nWhat's your choice?\t");
    scanf("%d",&option);

    if(option==1) ///input of the products
    {
        m=1;
        printf("\nHow Many Types of Different Products Are There?\t");
        scanf("%d",&prd_num);


        for(i=total;i-total<prd_num;i++) ///loop for inputing the products
        {

            printf("\n");
            printf("#%d\tName of The Product :\t",i+1);

            scanf("%c",&temp); /// temp statement to clear buffer
            scanf("%[^\n]",prd_name[i]);

            prd_id[i]=i+1;

            printf("\tQuantity of The Product , %s :\t",prd_name[i]);
            scanf("%d",&prd_qty[i]);

            printf("\tRate of The Product per piece , %s :\t",prd_name[i]);
            scanf("%f",&prd_rate[i]);

            printf("\tDiscount for The Product per piece , %s :\t",prd_name[i]);
            scanf("%f",&prd_disc[i]);

            prd_price[i]=prd_rate[i]*(1-(prd_disc[i]/100)+(vat/100)); ///sale price after cutting the discount

            total_prd=i+1;

            prd_delete_factor[i]=1;

            sale[i]=0;


        }

    }

    else if(option==2)
    {
        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }
        sl_no=0;
        display();
        for(i=0;i<total_prd;i++)
        {
            if(prd_delete_factor[i]==1)
            {
                sl_no++;

                printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",sl_no,prd_name[i],prd_id[i],prd_qty[i],prd_rate[i],prd_disc[i],vat,prd_price[i]);//map
            }

        }


        invalid_given_input:
        printf("\nNow How Many Products Do You Want to Change?\t");
        scanf("%d",&prd_change_num);

        if(prd_change_num>total)
        {
            printf("\nThere input is wrong. There Are Only %d products\n",total);
            goto invalid_given_input;
        }
        else
        {



           for(i=1;i<=prd_change_num;i++)
           {


                invalid_id_input:
                printf("\nEnter Product Id?\t");
                scanf("%d",&prd_id_num);

                for(j=0;j<total;j++)
                {
                    if(prd_id[j] == prd_id_num)
                    {
                        break;
                    }
                    else
                    {
                        if(j==total-1)
                        {
                            printf("\nThere is no such id available. Please Recheck");
                            goto invalid_id_input;

                        }
                    }
                }


                if(prd_id[j] == prd_id_num)
                {
                    Invalid_Input_Label:
                    printf("\nWhich Term to Change? If You Want to Change the Following Terms Press The Given Numbers.\n i.e. Name-->1\tQuantity-->2\n\tRate-->3\tDiscount-->4\t");
                    scanf("%d",&num_change);

                    if(num_change==1)
                    {
                        printf("\nGive The New Name...\t");
                        scanf("%c",&temp);
                        scanf("%[^\n]",prd_name[j]);
                    }
                    else if(num_change==2)
                    {
                        printf("\nGive The New Quantity...\t");
                        scanf("%d",&prd_qty[j]);
                    }
                    else if(num_change==3)
                    {
                        printf("\nGive The New Rate...\t");
                        scanf("%f",&prd_rate[j]);
                        prd_price[j]=prd_rate[j]*(1-(prd_disc[j]/100)+(vat/100));
                    }
                    else if(num_change==4)
                    {
                        printf("\nGive The New Discount...\t");
                        scanf("%f",&prd_disc[j]);
                        prd_price[j]=prd_rate[j]*(1-(prd_disc[j]/100)+(vat/100));
                    }
                    else
                    {
                        goto Invalid_Input_Label;
                    }
                }
            }
        }
    }


    else if(option==3)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }

prd_id_wrong:

        sl_no=0;
        display();
        for(j=0;j<total;j++)
        {
            if(prd_delete_factor[j]==1)
            {
                sl_no++;

                printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",sl_no,prd_name[j],prd_id[j],prd_qty[j],prd_rate[j],prd_disc[j],vat,prd_price[j]);//map
            }

        }

        printf("\nTo delete a product please enter the product id...\t");
        scanf("%d",&prd_id_delete);

        if(prd_id[prd_id_delete-1]==prd_id_delete)
        {
            prd_delete_factor[prd_id_delete-1]=0;
        }

        else
        {
            printf("\nThere is no such product id. Please recheck.");
            goto prd_id_wrong;
        }
    }


    else if(option==4)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }


        sl_no=0;
        printf("\n\tAll The Available Products Are...\n\n");

        display();
        for(j=0;j<total;j++)
        {
            if(prd_delete_factor[j]==1)
            {
                sl_no++;

                printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",sl_no,prd_name[j],prd_id[j],prd_qty[j],prd_rate[j],prd_disc[j],vat,prd_price[j]);//map
            }
        }
    }




    else if(option==5)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }


again_buy_label:


        prd_qty_factor=0;
        k=0;
        l=1;
        for(j=0;j<total;j++)
        {
                prd_qty_factor=prd_qty_factor+prd_qty[j];


                if(j==total-1 && prd_qty_factor==0)
                {

                       printf("\nAll The products has finished The Shop has nothing to sell");
                       goto exit;


                }

        }

        sl_no=0;
        printf("\n\tThe Products Available are... ... ...\n");

        display();
        for(j=0;j<total;j++)
        {
            if(prd_delete_factor[j]==1)
            {
                sl_no++;

                printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",sl_no,prd_name[j],prd_id[j],prd_qty[j],prd_rate[j],prd_disc[j],vat,prd_price[j]);//map

            }
        }

purchase_invalid_id_input_label:
        printf("\n\tWhich One To Buy?\n\tEnter The Correct Product ID...\t");
        scanf("%d",&prd_to_buy_id);
        if(prd_id[prd_to_buy_id-1]!=prd_to_buy_id || prd_delete_factor[prd_to_buy_id-1]!=1)
        {

            printf("The Product id is not there please check again\n");

            sl_no=0;
            printf("\n\tThe Products Available are... ... ...\n");

            display();
            for(j=0;j<total;j++)
            {
                if(prd_delete_factor[j]==1)
                {
                    sl_no++;

                    printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",sl_no,prd_name[j],prd_id[j],prd_qty[j],prd_rate[j],prd_disc[j],vat,prd_price[j]);//map
                }
            }

            goto purchase_invalid_id_input_label;

        }

        if(prd_qty[prd_to_buy_id-1]==0)
        {
            printf("\nThe Product has finished. Sorry.");
            goto asking_label_2;

        }

low_qty_level_label:
        printf("\n\tThe Quantity to buy?\t");
        scanf("%d",&prd_to_buy_qty);


        if(prd_qty[prd_to_buy_id-1]<prd_to_buy_qty)
        {
            if(prd_qty[prd_to_buy_id-1]==0)
            {
                printf("\nThe Product has finished");
                goto again_buy_label;

            }
            else
            {
asking_label:
                printf("\nNot enough Amount is available there. There are %d pieces\nTo buy less amount press (Y) or to quit buying this product press (N)\t",prd_qty[prd_to_buy_id-1]);
                getchar();
                low_qty_factor=getchar();


                if(low_qty_factor =='Y' || low_qty_factor=='y')
                {
                    goto low_qty_level_label;

                }
                else if(low_qty_factor =='N' || low_qty_factor=='n')
                {
                    printf("\nWant to buy anything else?(Y/N)\t");
                    getchar();
                    more_purchase_factor=getchar();

                    if(more_purchase_factor =='Y' || more_purchase_factor =='y')
                    {
                        goto again_buy_label;
                    }
                }

                else
                {
                    printf("\nInvalid Input");
                    goto asking_label;
                }
            }


        }
        else
        {
                prd_qty[prd_to_buy_id-1]=prd_qty[prd_to_buy_id-1]-prd_to_buy_qty;
                sale[prd_to_buy_id-1]=sale[prd_to_buy_id-1]+prd_to_buy_qty;
                prd_to_buy_price=prd_price[prd_to_buy_id-1]*prd_to_buy_qty;
                total_purchase=total_purchase+prd_to_buy_price;




asking_label_2:
                printf("\nWant to buy anything else?(Y/N)\t");
                getchar();
                more_purchase_factor=getchar();



                if(more_purchase_factor=='Y' || more_purchase_factor=='y')
                {
                    goto again_buy_label;
                }
                else if(more_purchase_factor=='N' || more_purchase_factor=='n')
                {

                }
                else
                {
                    printf("\nInvalid Input");
                    goto asking_label_2;
                }
        }


exit:
        if(total_purchase!=0)
        {
            printf("\n\n\tThe Total bill is %g bdt\n\t\tThanks for buying.",total_purchase);
        }

        else
        {
            printf("\n\n\tThere was no purchase done. Thank you.");
        }



    }

    else if(option==6)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }

        else
        {

            if(l!=1)
            {
                printf("\nWithout Any Purchase we can not declare any highest selling product\n");
                goto option_selector_label;
            }

            sale_count=sale[0];
            for(j=0;j<total;j++)
            {

                if(sale[j]>=sale_count)
                {
                    sale_count=sale[j];

                }
                else
                {
                    sale_count=sale_count;
                }


            }


            printf("\nThe top selling products are...\n");

            for(j=0;j<total;j++)
            {
                if(sale[j]==sale_count && prd_delete_factor[j]==1)
                {


                    printf("\tid %d\t%s\n",prd_id[j],prd_name[j]);

                }

            }


        }

    }


    else if(option==7)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }


    	if(l!=1)
        {
            printf("\nWithout Any Purchase we can not declare any lowest selling product\n");
            goto option_selector_label;
        }

        	low_sale_count=sale[0];
        	for(j=0;j<total;j++)
        	{
        	    if(sale[j]<=low_sale_count)
        	    {
        	        low_sale_count=sale[j];

        	    }
        	    else
        	    {
        	        low_sale_count=low_sale_count;

        	    }
        	}
        	    printf("\nThe Lowest selling products Are...\n");

        	    for(j=0;j<total;j++)
        	    {
        	        if(sale[j]==low_sale_count && prd_delete_factor[j]==1)
        	        {
        	            printf("\tid %d\t%s\n",prd_id[j],prd_name[j]);
        	        }
        	    }

    }

    else if(option==8)
    {


        k=0;
        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }


    	printf("\nProducts with zero quantity are...\n");
    	for(j=0;j<total;j++)
    	{
    		if(prd_qty[j]==0 && prd_delete_factor[j]==1)
    		{
    			 printf("\tid %d\t%s\n",prd_id[j],prd_name[j]);
    			 k=1;

    		}
    		else
    		{
    		    if(j==total-1 && prd_delete_factor[j]==1 && k!=1)
                {
                    printf("\nNo product found of zero quantity\n");
                }

    		}
    	}
    }


    else if(option==9)
    {
        return 0;
    }

    else if(option==10)
    {

        if (m!=1)
        {
            printf("\nYou must input the products at first...");
            goto option_selector_label;
        }

        printf("\n\tAll The Products Are...\n\n");


        display();
        for(j=0;j<total;j++)
        {

            printf("\n\t%d\t%s\t%d\t%d\t%g\t%g\t%g\t%g",j+1,prd_name[j],prd_id[j],prd_qty[j],prd_rate[j],prd_disc[j],vat,prd_price[j]);//map
        }
    }

    else if(option==11)
    {
        printf("\nWhat will be the new VAT?\t");
        scanf("%f",&vat);

        for(j=0;j<total;j++)
        {
            prd_price[j]=prd_rate[j]*(1-(prd_disc[j]/100)+(vat/100));
        }
    }


    else
    {
        printf("\nInvalid Input. Please Check The Options...");
    }

    printf("\n\n");
    goto option_selector_label;





    printf("\n\n\n ");
    return 0;
}
