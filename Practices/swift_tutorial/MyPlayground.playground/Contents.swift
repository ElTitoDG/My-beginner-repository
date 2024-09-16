import Cocoa

var fruits = [
    "segunda": "manzana",
    "primera": "pera",
    "tercera": "limas"
]
var sortedFruits = fruits.sorted {$0.key < $1.key}
print(sortedFruits)
