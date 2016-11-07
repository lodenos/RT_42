Projet RayTracing

Partie Obligatoire

    - Exopose sans recalcule                                        [x] - Fait

    - Les Objets

        -   4 Objets simple                                         [x] - Fait
        -   translation des Objets                                  [x] - Fait
        -   Rotation des Objets                                     [.] - En Cours ...

    - REM : Rapide Eye Movement                                     [x] - Fait

    - Lumiere

        -   L'ombre des Objets                                      [x] - Fait
        -   L'ombre multi-spot                                      [x] - Fait
        -   La Brillance                                            [x] - Fait
        -   Le Multi-spot                                           [x] - Faitß

Partie Optionnelle

    - Fichier de scene                                              [x] - Fait

    - Fichier de scene ++                                           [x] - Fait

    - Lumiere ambiante                                              [x] - Fait

    - Ambiante ++                                                   [x] - Fait

    - Objets limites

        -   Decoupe basique d'un Objet en XYZ                       [0]
        -   Choix de l'axe de decoupe                               [0]
        -   Rotation et Translation de l'Objet decouper             [0]
        -   Decoupe unique a chaque Objet                           [0]
        -   Decoupe du Plan                                         [0]

    - Perturbations

        -   Normal  --->    "impression d'avoir des vaguelettes"    [x] - Fait
        -   Couleur --->    "Le Damier"                             [0]
        -   Couleur --->    "Texture Procedurale"                   [0]
        -   Couleur --->    "Bruit de Perlin"                       [.] - En Cours ...

    - Lumiere Directe                                               [0]

    - Lumiere Paralelle --->    "Lumiere Directionnel"              [0]

    - Reflexion & Transparence
    
        -   Reflexion   --->    "Effet Miroir"                      [.] - En Cours ...
        -   Change % de reflexion                                   [.] - En Cours ...
        -   La Transparence                                         [0]
        -   Indice de refraction                                    [0]
        -   Change le % de transparence                             [0]

    - Ombres de l'Objet Transparent                                 [0]

    - Textures I

        -   Applique une texture au moins sur 1 Objet               [0]
        -   Applique une texture sur les 4 Objets de base           [0]
        -   Etire ou Contracte une Texture                          [0]
        -   Faire bouge la texture sur l'Objet                      [0]
        -   Texture au format jpeg, png, ...                        [0]

    - Texture II

        -   La Texture sert a modifier la normal                    [0]
        -   La Texture sert a la transparence de l'objet            [0]
        -   La Texture sert a la limite de decoupe de l'Objet       [0]
        -   La Texture sert de diapositive                          [0]

    - Objets Compose

        -   Un Cube                                                 [0]
        -   Un Verre                                                [0]
        -   Bouge les Objets compose                                [0]

    - Objets simpe suplementaire

        -   Une autre primitive                                     [.] - En Cours ...

    - Effet visuel classique

        -   Anti-aliasing "Super-sampling"                          [x] - Fait
        -   Effet Cartoon                                           [0]
        -   Motion Blur ou Blur                                     [0]
        -   Filtre sepia ou autre filtre de couleur                 [x] - Fait
        -   Stereoscopie Simple                                     [0]

    - Effets Technique

        -   Calcule en Cluster                                      [.] - En Cours ...
        -   Calcule multi-tread                                     [x] - Fait
        -   GPU                                                     [x] - Fait
        -   Sauvguarde d'une Image dans RT                          [0]

    - Environnement

        -   Interface Sommaire "Bare de Progression"                [0]
        -   Interface Chiade en GTK, ...                            [0]
        -   Modiffe les variable de la scene                        [0]
        -   Paramettre plusieur rendu                               [0]
        -   Ajjoute des Objets dans la scene                        [0]

    - Travaille en Groupe                                           [0]

    - Les Objets Exotique

        -   Cube Troue                                              [0]
        -   Une Nappe                                               [0]
        -   Le Tore                                                 [.] - En Cours ...
        -   Resolution d'equation                                   [0]
        -   Fractal                                                 [0]

    - En vrac

        -   Secance video du RT                                     [0]
        -   Gestion du Fichier .pov, .3ds, .obj                     [0]
        -   Enrelief sur TV 3D ou Oculuse Rift                      [0]
        -   Spot non Ponctuel                                       [0]
        -   Autre "Au choix"                                        [0]

    - Ruban de Moebius                                              [0]

    - Caustics et/ou Global illumination                            [0]

    - Rendu Magnifique                                              [0]

Rapport de bug

    -   Leaks    : 1 leak par resize de la fenêtre
    -   Problème : La fusion des lumieres speculaire
    -   Problème : La fusion des couleurs des spots sur la lumiere speculaire
    -   Problème : Mauvaise valeur attribué pour la lumiere speculaire
    -   Problème : Le plan doit avoir 2 normal qui pointes dans les 2 directions
    -   Problème : La lumiere ambiant est mal gérée
    -   Problème : La lumiere speculaire apparait aussi quand on est derrière l'objet
    -   Problème : Un objet noir apparaît comme gris
    -   Problème : Problème aux changements de type de fenêtrage
