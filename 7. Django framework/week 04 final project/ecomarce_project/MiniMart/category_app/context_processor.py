from category_app.models import CategoryModel

def menu_links(request):
    links = CategoryModel.objects.all()
    return dict(links= links)