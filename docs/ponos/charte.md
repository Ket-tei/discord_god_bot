# Charte

## Direction artistique
L'interface doit refléter une esthétique moderne, claire et adaptée aux outils Discord. Elle doit prioriser la simplicité d'utilisation, avec des éléments visuels qui guident les utilisateurs vers les actions principales (soumission de réponses, gestion des rôles, notifications). Les composants doivent être alignés sur le style des interfaces Discord officielles, avec des nuances de gris et des accents de couleur pour souligner les actions critiques (validation, erreurs).

## Palette de couleurs
- **Primaire** : `#7289DA` (bleu Discord) pour les boutons d'actions et les notifications importantes.
- **Secondaire** : `#5865F2` (bleu foncé) pour les éléments de navigation et les titres.
- **Texte** : `#2F363F` (gris foncé) pour le contenu principal, `#FFFFFF` (blanc) pour le contraste sur les backgrounds clairs.
- **Succès** : `#57F287` (vert clair) pour les états de validation réussie.
- **Erreur** : `#ED4264` (rouge Discord) pour les messages d'erreur et les alertes.
- **Arrière-plan** : `#111111` (noir) pour le dashboard administrateur, `#2F363F` pour les interfaces utilisateur.

## Typographie
- **Titres** : `Inter` (sans serif), 24px, gras, espacement 1.5x.
- **Corps** : `Inter`, 16px, espacement 1.5x, couleur `#FFFFFF`.
- **Texte secondaire** : `Inter`, 14px, italique, couleur `#A9A9A9`.

## Espacement
- **Marges internes** : 24px pour les sections, 16px pour les éléments composants.
- **Espacement vertical** : 24px entre les blocs de contenu.
- **Padding des boutons** : 12px vertical, 20px horizontal.
- **Gaps entre éléments** : 16px horizontalement, 24px verticalement.

## Composants d'interface
- **Card de notification** : Arrière-plan `#111111`, bordures arrondies (8px), bordure inférieure `#2F363F`, texte blanc.
- **Formulaire de gestion** : Champs de saisie avec bordure `#5865F2`, focus bleu clair, icônes en gris clair.
- **Tableau de gestion** : Lignes alternées (noir et gris foncé), icônes d'action en bleu primaire.
- **Barre de statut** : Barre en bas de l'écran avec icônes et messages en bleu clair sur fond noir.

## Principes UX/UI
- **Accessibilité** : Contraste minimum 4.5:1 pour le texte, labels explicites pour les formulaires, support pour lecteurs d'écran.
- **États vides** : Message "Aucune réponse soumise" avec icône et lien pour ajouter une réponse.
- **Erreurs** : Messages d'erreur en rouge avec suggestion corrective (ex: "Veuillez entrer un texte valide").
- **Chargement** : Indicateur de rotation bleu clair sur fond gris, texte "Chargement..." en blanc.

## Hypothèses
- La palette de couleurs s'inspire du style Discord pour une cohérence visuelle.
- Les composants sont simplifiés pour un usage rapide, sans surcharge visuelle.
- Les états d'erreur et de chargement sont visuellement distincts pour éviter la confusion.