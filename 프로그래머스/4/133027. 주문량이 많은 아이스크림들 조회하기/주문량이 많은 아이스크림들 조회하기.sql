select n.flavor
from (
select f.flavor, sum(f.total_order) + sum(j.total_order) as total_order
from first_half f 
join (
    select SHIPMENT_ID, flavor, sum(total_order) as total_order
    from july
    group by flavor
) j on f.SHIPMENT_ID=j.SHIPMENT_ID
group by flavor
order by total_order desc limit 3) n;