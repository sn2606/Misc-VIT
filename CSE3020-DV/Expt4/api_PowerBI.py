import pandas as pd
from datetime import datetime
from datetime import timedelta
import requests
import time
import random

##class for data_generation


def data_generation():
    surr_id = random.randint(1, 3)
    speed = random.randint(20,200)
    date = datetime.today().strftime("%Y-%m-%d")
    time = datetime.now().isoformat()

    return [surr_id, speed, date, time]


if __name__ == '__main__':

    REST_API_URL = 'https://api.powerbi.com/beta/d4963ce2-af94-4122-95a9-644e8b01624d/datasets/582ede41-4889-43c4-be65-f6a190a472ef/rows?key=rf%2BQVP7sYa8wPcnwq4HNCZSUaF%2BkgsDEEtpb%2BNApcWKefZu%2BwWeeub5uaqO2BdCR4Vdt%2BNf6Gflo8yNyEHxQIQ%3D%3D'

    while True:
        data_raw = []
        for i in range(1):
            row = data_generation()
            data_raw.append(row)
            print("Raw data - ", data_raw)

        # set the header record
        HEADER = ["surr_id", "speed", "date", "time"]

        data_df = pd.DataFrame(data_raw, columns=HEADER)
        data_json = bytes(data_df.to_json(orient='records'), encoding='utf-8')
        print("JSON dataset", data_json)

        # Post the data on the Power BI API
        req = requests.post(REST_API_URL, data_json)

        print("Data posted in Power BI API")
        time.sleep(2)