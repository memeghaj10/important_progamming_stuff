class Codec {
public:
    
    
    
    TreeNode * fun ( string s  , int &index )
    {
        if ( index >= s.length() or s [ index ] == 'X' )
        {
            index += 2 ; 
            return NULL ; 
        }
        
        string temp ; 
        
        while ( s[ index ] != ' ' )
        {
            temp += s [ index ] ; 
            index ++ ; 
        }
        index ++ ; 
        TreeNode * root = new TreeNode ( stoi ( temp ) ) ;
        root -> left = fun ( s , index  ) ; 
        root -> right = fun ( s , index ) ;
        
        return root ; 
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root)
    {
        if ( !root )
                return "X " ; 
        string ans ; 
        
        ans = ans + to_string ( root -> val ) + " " ; 
        ans = ans + serialize ( root -> left ) ; 
        ans = ans + serialize ( root -> right ) ; 
        
        
        
        
        return ans ; 
        
    }
    TreeNode* deserialize(string s)
    {
        
       
        int index = 0 ; 
        return fun ( s , index  ) ; 
        
        
        
    }
};