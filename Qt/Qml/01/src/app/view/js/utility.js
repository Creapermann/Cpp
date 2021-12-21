var fruitList = [{text: "Apple"}, {text: "Bannana"}, 
                 {text: "Berry"}, {text: "Grape"}]

var animalList = [{text: "Doggo"}, {text: "Cat"}, 
                  {text: "Elephant"}, {text: "Ape"}]

var emptyList = []

var currentDefaultList = fruitList;



function deleteItemFromComboBoxAndRotateSelection()
{
    editableComoBoxList.remove(editableComoboBox.currentIndex);
    
    if(editableComoboBox.currentIndex === editableComoBoxList.count && 
            editableComoboBox.currentIndex !== 0);
    editableComoboBox.decrementCurrentIndex();
}

function setListContent(preferedList = null)
{
    let list;
    if(preferedList !== null)
        list = preferedList;
    else
        list = currentDefaultList;
    
    currentDefaultList = list;
    
    editableComoBoxList.clear();
    list.forEach( function(arg)
    {
        editableComoBoxList.append({text: arg.text});
    });
    editableComoboBox.currentIndex = 0;
    
    newItemText.text = "";
}