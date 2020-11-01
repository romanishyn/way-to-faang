/*
https://leetcode.com/problems/design-in-memory-file-system/
*/

#include <string>
#include <memory>
#include <vector>
#include <unordered_map>

using std::string;

namespace {
/*
*/
class FileSystem {
    struct Entry {
        using Ptr = std::unique_ptr< Entry >;

        bool isFile{ false };
        std::string content;
        std::unordered_map< std::string, Ptr > children;
    };

    Entry::Ptr root;

public:
    FileSystem()
    :   root{ std::make_unique< Entry >() }
    {
    }

    vector<string> ls(string path) {
        auto entry = root.get();

        auto components = getComponents( path );
        for( const auto& component : components ) {
            entry = entry->children[ component ].get();
        }

        if( entry->isFile )
            return { components.back() };
        else {
            std::vector< std::string > result;
            for( const auto& [name, _] : entry->children )
                result.push_back( name );

            std::sort( begin( result), end( result ) );
            return result;
        }
    }

    void mkdir(string path) {
        makeEntry( path );
    }

    void addContentToFile(string filePath, string content) {
        auto& entry = makeEntry( filePath );
        entry.isFile = true;
        entry.content += content;
    }

    string readContentFromFile(string filePath) {
        return makeEntry( filePath ).content;
    }

private:
    Entry& makeEntry( std::string_view path ) {
        auto components = getComponents( path );

        auto entry = root.get();
        for( const auto& component : components ) {
            if( ! entry->children.count( component ) ) {
                entry->children.try_emplace( component, std::make_unique< Entry >() );
            }
            entry = entry->children[ component ].get();
        }

        return *entry;
    }

    std::vector< std::string > getComponents( std::string_view path ) {
        std::vector< std::string > components;
        const int pathSize = path.size();
        for( int idx = 1; idx < pathSize; ++idx ) {
            std::string component;
            while( idx < pathSize && path[ idx ] != '/' )
                component.push_back( path[ idx++ ] );

            components.push_back( std::move( component ) );
        }

        return components;
    }
};
} //namespace
