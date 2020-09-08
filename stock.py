from yahoo_fin import stock_info
company_name=input("Company Name:-  ")
db={'Apple': 'AAPL', 'Amgen': 'AMGN', 'American Express': 'AXP','Amazone':'AMZN', 'The Boeing Company': 'BA',
    'Caterpillar': 'CAT', 'Cisco': 'CSCO', 'The Walt Disney Company': 'DIS', 'Dow': 'DOW', 'Goldman Sachs': 'GS',
    'Home Depot': 'HD', 'IBM': 'IBM', 'Intel': 'INTC', 'Johnson & Johnson': 'JNJ', 'Coca Cola ': 'KO',
    "McDonald": 'MCD', 'Microsoft': 'MSFT', 'NIKE': 'NKE', 'The Procter & Gamble Company': 'PG', 'Visa': 'V',
    'Walgreens Boots Alliance': 'WBA', 'Walmart': 'WMT'}
price=float(input("Enter your buying price:-"))
aim=float(input("Return Percentage:--  "))
while True:
    curr_price=stock_info.get_live_price(db[company_name])
    temp=(price*aim)/100
    if curr_price>=temp:
        print("Goal Achived sell the stocks")
        break
    elif curr_price<=(price/2):
        print("Stock Price become very low ")
        break




