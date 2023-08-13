# seriallizer er kaj holo fronted theke jei data backend er jonno ana hobe 
# seriallizer seta jeson format e convert kore backend k pathabe and database a save hobe

from rest_framework import serializers
from book_restApi.models import BookStoreModel

class BookSerializer(serializers.ModelSerializer):
    class Meta:
        model = BookStoreModel
        fields = '__all__'