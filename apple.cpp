def make_change(amount, coins):
//coinsӦ���ǰ��մӴ�С����ı�ֵ�б�
    coins.sort(reverse=True)  //ȷ����ֵ�ǴӴ�С�����
    result = []
    for coin in coins:
        // ��ǰ������ö��ٸ�
        while amount >= coin:
            result.append(coin)
            amount -= coin
    return result
 
//����
coins = [100, 50, 20, 10, 5, 1]  //���õı�ֵ
amount = 378  // ��Ҫ����Ľ��
change = make_change(amount, coins)
print(f"��Ҫ��Ӳ��: {change}")
print(f"Ӳ������: {len(change)}")
