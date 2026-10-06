#ifndef GUARD_SHOP_CRITERIA_H
#define GUARD_SHOP_CRITERIA_H

void TryBuildDynamicShopItemList(const u16 **ogItemList, u16 *resultingTotal);
void TryFreeDynamicShopItemList(const u16 **ogItemList);

// Add new Criterias below!

bool32 ShopCriteriaBadge5(enum Item item);
bool32 ShopCriteriaBadge6(enum Item item);
bool32 ShopCriteriaBadge7(enum Item item);
bool32 ShopCriteriaBadge8(enum Item item);
bool32 ShopCriteriaBadge1Rematch(enum Item item);
bool32 ShopCriteriaBadge2Rematch(enum Item item);
bool32 ShopCriteriaBadge3Rematch(enum Item item);
bool32 ShopCriteriaBadge4Rematch(enum Item item);
bool32 ShopCriteriaIsChampion(enum Item item);

#endif // GUARD_SHOP_CRITERIA_H
