select fo.PRODUCT_ID, fp.PRODUCT_NAME, sum(fo.AMOUNT) * fp.price as TOTAL_SALES
from food_product as fp 
join food_order as fo 
on fp.product_id=fo.product_id
where fo.PRODUCE_DATE >= '2022-05-01' 
    and fo.PRODUCE_DATE <= '2022-05-31'
group by fo.product_id, fp.PRODUCT_NAME, fp.price
order by 
    TOTAL_SALES desc, 
    fp.product_id asc;

# select * from food_product join food_order on food_product.product_id=food_order.product_id;

