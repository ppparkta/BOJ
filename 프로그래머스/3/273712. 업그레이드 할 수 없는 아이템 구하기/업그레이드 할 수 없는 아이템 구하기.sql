select i.item_id, i.item_name, i.rarity
from ITEM_INFO i
where i.item_id not in (
    select it.PARENT_ITEM_ID
    from ITEM_TREE it
    where it.PARENT_ITEM_ID is not null
)
order by i.item_id desc;