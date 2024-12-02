data Component = TextBox {name :: String, text :: String}
               | Button {name :: String, value :: String}
               | Container {name :: String, children :: [Component]} deriving Show

-- tady je ten basic shit
gui :: Component
gui = Container "misa" [
    Container "capek" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj",
        TextBox "tb" "nevim"
    ],
    Container "capek2" [
        Button "ahoj_btn" "ahoj",
        Button "ahoj_btn" "ahoj"],
    Container "capek 3" []
        ]

tb :: Component
tb = TextBox "tb" "nevim"


-- zadani 2

{-
data Entity = Point Double Double 
            | Circle (Double, Double) Double 
            | Container [Entity]
-}

countButtons :: Component -> Int
countButtons (Button a b) = 1
countButtons (TextBox c d) = 0
countButtons (Container x y) = sum (map countButtons y)

addElement :: Component -> Component -> String -> Component
addElement (Container name children) toAdd containerName | name == containerName = (Container name (children ++ [toAdd]))
                                                         | otherwise = Container name (map (\x -> addElement x toAdd containerName) children)
addElement component _ _ = component


-- zadani 4
data Attribute = Attribute String String

data Tag = Tag String [Attribute] [Tag]

data HTMLDocument = HTMLDocument [Tag]

dokument :: HTMLDocument 
dokument = HTMLDocument [(Tag "<head>" [Attribute "nevim" "ahoj"] []),(Tag "<body>" [Attribute "nevim" "ahoj"] [(Tag "<h1>" [Attribute "text" "ahoj"] [])])]


listButtonNames :: Component -> [String]
listButtonNames (Button name _) = [name]
listButtonNames (Container name children) = concat (map listButtonNames children)

changeText :: Component -> String -> String -> Component
changeText (TextBox name oldStr) token newStr | name == token = (TextBox name newStr)
                                              | otherwise = (TextBox name oldStr)
changeText (Container name children) token newStr = Container name (map (\x -> changeText x token newStr) children)
changeText component _ _ = component                                      


-- zadani 5

listAllButtons :: Component -> [Component]
listAllButtons (Button name value) = [Button name value]
listAllButtons (Container name children) = concat (map listAllButtons children)
listAllButtons component = []

removeAllButtons :: Component -> Component -- zla funkce kamo nevim jak jinak vyresit nez takto
removeAllButtons (TextBox name value) = TextBox name value
removeAllButtons (Container name children) = Container name (map removeAllButtons (filter(isNotButton) children))
    where 
        isNotButton (Button _ _ )= False
        isNotButton _ = True

-- zadani 6

listAllNames :: Component -> [String]
listAllNames (Button name _ ) = [name]
listAllNames (TextBox name _ ) = [name]
listAllNames (Container name children ) = [name] ++ concat (map listAllNames children)

removeElements :: Component -> [String] -> Component -- opet docela bolestive
removeElements (Container name children ) names =  Container name (map (`removeElements` names) (filter (hasntName) children))
    where 
        hasntName (Button name _ ) = name `notElem` names
        hasntName (TextBox name _ ) = name `notElem` names
        hasntName (Container name _ ) = name `notElem` names
removeElements component _ = component

-- na fotce neni cislo

countAllComponents :: Component -> Int
countAllComponents (Button _ _) = 1
countAllComponents (TextBox _ _) = 1
countAllComponents (Container _ children) = sum (map (countAllComponents) children) + 1

removeEmptyContainers :: Component -> Component
removeEmptyContainers (Container name children) = Container name (map (removeEmptyContainers) (filter isNotEmpty children))
    where 
        isNotEmpty (Container _ children) | length children > 0 = True
                                          | otherwise  = False
        isNotEmpty component = True
removeEmptyContainers component = component
