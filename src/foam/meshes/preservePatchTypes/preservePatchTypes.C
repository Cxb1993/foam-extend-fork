/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | foam-extend: Open Source CFD
   \\    /   O peration     |
    \\  /    A nd           | For copyright notice see file Copyright
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of foam-extend.

    foam-extend is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    foam-extend is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with foam-extend.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "preservePatchTypes.H"
#include "polyBoundaryMeshEntries.H"
#include "dictionary.H"

// * * * * * * * * * * * * * * * Global Functions  * * * * * * * * * * * * * //

void Foam::preservePatchTypes
(
    const objectRegistry& obr,
    const word& meshInstance,
    const fileName& meshDir,
    const wordList& patchNames,
    wordList& patchTypes,
    const word& defaultFacesName,
    word& defaultFacesType,
    wordList& patchPhysicalTypes
)
{
    dictionary patchDictionary;

    {
        IOobject patchEntriesHeader
        (
            "boundary",
            meshInstance,
            meshDir,
            obr,
            IOobject::MUST_READ,
            IOobject::NO_WRITE,
            false
        );

        if (patchEntriesHeader.headerOk())
        {
            // Create a list of entries from the boundary file.
            polyBoundaryMeshEntries patchEntries(patchEntriesHeader);

            forAll(patchEntries, patchi)
            {
                patchDictionary.add(patchEntries[patchi]);
            }
        }
    }

    if (patchDictionary.size())
    {
        forAll(patchNames, patchi)
        {
            if (patchDictionary.found(patchNames[patchi]))
            {
                const dictionary& patchDict =
                    patchDictionary.subDict(patchNames[patchi]);

                patchDict.lookup("type") >> patchTypes[patchi];

                patchDict.readIfPresent("geometricType", patchTypes[patchi]);
                patchDict.readIfPresent
                (
                    "physicalType",
                    patchPhysicalTypes[patchi]
                );
            }
        }

        if (patchDictionary.found(defaultFacesName))
        {
            const dictionary& patchDict =
                patchDictionary.subDict(defaultFacesName);

            patchDict.readIfPresent("geometricType", defaultFacesType);
        }
    }

    Info << nl << "Default patch type set to " << defaultFacesType << endl;
}


// ************************************************************************* //
