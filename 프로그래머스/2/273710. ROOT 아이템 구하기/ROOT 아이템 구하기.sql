-- 코드를 작성해주세요
select i.item_id, i.item_name
from ITEM_INFO i
where i.item_id in (select it.item_id from item_tree it where it.PARENT_ITEM_ID is null)
order by i.item_id;