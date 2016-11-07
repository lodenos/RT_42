__Projet RayTracing

__Partie Obligatoire

    - Exopose sans recalcule

    - Les Objets

        -   4 Objets simple
        -   translation des Objets
        -   Rotation des Objets

    - REM : Rapide Eye Movement

    - Lumiere

        -   L'ombre des Objets
        -   L'ombre multi-spot
        -   La Brillance
        -   Le Multi-spot

__Partie Optionnelle

    - Fichier de scene

    - Fichier de scene ++

    - Lumiere ambiante

    - Ambiante ++

    - Objets limites

        -   Decoupe basique d'un Objet en XYZ
        -   Choix de l'axe de decoupe
        -   Rotation et Translation de l'Objet decouper
        -   Decoupe unique a chaque Objet
        -   Decoupe du Plan

    - Perturbations

        -   Normal  --->    "impression d'avoir des vaguelettes"
        -   Couleur --->    "Le Damier"
        -   Couleur --->    "Texture Procedurale"
        -   Couleur --->    "Bruit de Perlin"

    - Lumiere Directe

    - Lumiere Paralelle --->    "Lumiere Directionnel"

    - Reflexion & Transparence
    
        -   Reflexion   --->    "Effet Miroir"
        -   Change % de reflexion
        -   La Transparence
        -   Indice de refraction
        -   Change le % de transparence

    - Ombres de l'Objet Transparent

    - Textures I

        -   Applique une texture au moins sur 1 Objet
        -   Applique une texture sur les 4 Objets de base
        -   Etire ou Contracte une Texture
        -   Faire bouge la texture sur l'Objet
        -   Texture au format jpeg, png, ...

    - Texture II

        -   La Texture sert a modifier la normal
        -   La Texture sert a la transparence de l'objet
        -   La Texture sert a la limite de decoupe de l'Objet
        -   La Texture sert de diapositive

    - Objets Compose

        -   Un Cube
        -   Un Verre
        -   Bouge les Objets compose

    - Objets simpe suplementaire

        -   Une autre primitive

    - Effet visuel classique

        -   Anti-aliasing "Super-sampling"
        -   Effet Cartoon
        -   Motion Blur ou Blur
        -   Filtre sepia ou autre filtre de couleur
        -   Stereoscopie Simple





Ce qu'il reste à faire cette semaine "Week 1"

    -   La rotation de tout les objets.                                         |   impératif Master
    -   REM à faire "Les mouvements de la camera et position dans l'espace"     |   impératif Master
    -   Fichier de scene propre à RT
    -   Fichier à gere ".obj" & ".mtl"
    -   Mettre OpenCL operationnel comme le code en c                           |   impératif OpenCL
    -   Intégrer le VBO "Vertex Buffer Object"                                  |   impératif OpenCL

Les différents problèmes & bug

    -   Leaks    : 1 leak par resize de la fenêtre                              |   impératif Leaks
    -   Problème : La fusion des lumieres speculaire
    -   Problème : La fusion des couleurs des spots sur la lumiere speculaire
    -   Problème : Mauvaise valeur attribué pour la lumiere speculaire
    -   Problème : Le plan doit avoir 2 normal qui pointes dans les 2 directions
    -   Problème : La lumiere ambiant est mal gérée
    -   Problème : La lumiere speculaire apparait aussi quand on est derrière l'objet
    -   Problème : Un objet noir apparaît comme gris
    -   Problème : Problème aux changements de type de fenêtrage
