def make_change(amount, coins):
//coins应该是按照从大到小排序的币值列表
    coins.sort(reverse=True)  //确保币值是从大到小排序的
    result = []
    for coin in coins:
        // 当前面额能用多少个
        while amount >= coin:
            result.append(coin)
            amount -= coin
    return result
 
//测试
coins = [100, 50, 20, 10, 5, 1]  //可用的币值
amount = 378  // 需要找零的金额
change = make_change(amount, coins)
print(f"需要的硬币: {change}")
print(f"硬币数量: {len(change)}")
