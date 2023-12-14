import requests

# Replace 'your_sync_link' with the actual sync link
sync_link = https://swissdiamstock.fantasy.mn:7600/stock/loose.csv

# Make a GET request to the sync link
response = requests.get(sync_link)

if response.status_code == 200:
    data = response.json()

    # Assuming 'internal_comments' is the key containing Internal Comments
    if 'internal_comments' in data:
        internal_comments = data['internal_comments']

        # Remove commas from Internal Comments
        cleaned_internal_comments = internal_comments.replace(',', '')

        # Update the data with cleaned Internal Comments
        data['internal_comments'] = cleaned_internal_comments

        # Assuming you have an endpoint to update the data
        update_url = 'your_update_endpoint'
        update_response = requests.post(update_url, json=data)

        if update_response.status_code == 200:
            print("Internal Comments updated successfully.")
        else:
            print(f"Error updating Internal Comments. Status code: {update_response.status_code}")
    else:
        print("Error: 'internal_comments' key not found in the data.")
else:
    print(f"Error fetching data from the sync link. Status code: {response.status_code}")
