# Generated by Django 4.2.4 on 2023-08-04 08:45

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('book', '0002_alter_bookstoremodel_last_pub'),
    ]

    operations = [
        migrations.AlterField(
            model_name='bookstoremodel',
            name='last_pub',
            field=models.DateTimeField(auto_now=True),
        ),
    ]
